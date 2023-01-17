/**
* Alfredo Renteria
* Leetcode Problem #322: Coin Change
* Grind 75, Leetcode 75 Level 2 - Medium
* @Topics: Array, Dynamic Programming, BFS
* Recursive Top Down: @Time: O(S * n) @Space: O(S)
* Where S is the amount and n is the size of coins
* Iterative Bottom Up: @Time: O(S * n) @Space: O(S)
*/

//Recursive Top Down
int memo(vector<int>& coins, int rem, vector<int>& dp) {
    constexpr int MAX = numeric_limits<int>::max();
    
    if (rem < 0) {
        return -1;
    } else if (rem == 0) {
        return 0;
    } else if (dp[rem - 1] != 0) {
        return dp[rem - 1];
    }
    
    int min = MAX;

    for (auto const& coin : coins) {
        int res = memo(coins, rem - coin, dp);
        if (res >= 0 && res < min) {
            min = res + 1;
        }
    }

    if (min != MAX) {
        dp[rem - 1] = min;
    } else {
        dp[rem - 1] = -1;
    }
    
    return dp[rem-1];
}

int coinChange(vector<int>& coins, int amount) {
    if (amount <= 0) {
        return 0;
    }

    vector<int> dp(amount, 0);
    
    int res = memo(coins, amount, dp);
    
    return res;
}

//Iterative Bottom Up
int coinChange(vector<int>& coins, int amount) {
    const int n = coins.size();
    //Tabulate where index represents the amount to make up
    //And value is the # of coins needed
    vector<int> dp(amount+1, amount+1);
    //Zero coins to make up zero amount
    dp[0] = 0;
    
    //For all amounts that can be made
    for (int i = 1; i <= amount; i++) {
        //Look at different coin denominations
        for (const auto& coin : coins) {
            //If curr. coin is not greater than the curr. amount
            if (coin <= i) {
                //Get the fewest # of coins needed to make up the curr. amount
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    //Amount cannot be made up by any combo of coins
    if (dp[amount] > amount) {
        return -1;
    }
    
    //Return fewest coins needed to make up amount
    return dp[amount];
}
