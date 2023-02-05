/**
* Alfredo Renteria
* Leetcode Problem #55: Jump Game
* Grind 75, Leetcode Dynamic Programming Level 1 - Medium
* @Topics: Array, Dynamic Programming, Greedy
* Bottom Up: @Time: O(n) @Space: O(n)
* Where n is the size of nums
* Top Down: @Time: O(n) @Space: O(n)
*/

#include <algorithm>
#include <iostream>
#include <vector>

//Bottom Up Dynamic Programming
bool canJump(std::vector<int>& nums) {
    const int n = nums.size();
    
    if (n == 1) {
        return true;
    }

    std::vector<int> dp(n, 0);
    dp[0] = nums[0];
    
    for (int i = 1; i < n; i++) {
        if (dp[i-1] >= i) {
            dp[i] = std::max(dp[i-1], i + nums[i]);
        }
    }
    
    return dp[n-1] >= n-1;
}

//Top Down Dynamic Programming
bool memo(std::vector<int>& nums, std::vector<int>& memo, int i) {
    const int finalStep = nums.size()-1;
    
    if (i == finalStep) {
        return true;
    } else if (memo[i] != -1) {
        return memo[i] == 1;
    }
    
    int furthestJump = std::min(finalStep, i + nums[i]);
    
    for (int j = i + 1; j <= furthestJump; j++) {
        if (memo(nums, memo, j)) {
            memo[i] = 1;
            
            return true;
        }
    }

    memo[i] = 0;
    
    return false;
}

bool canJump(std::vector<int>& nums) {
    const int n = nums.size();
    
    if (n == 1) {
        return true;
    }

    std::vector<int> memo(n, -1);
    memo[n-1] = 1;
    
    return memo(nums, memo, 0);
}