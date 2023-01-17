/**
* Alfredo Renteria
* Leetcode Problem #198: House Robber
* Grind 75, Leetcode 75 Level 2 - Medium
* @Topics: Array, Dynamic Programming
* Recursive Top Down: @Time: O(n) @Space: O(n)
* Where n are the # of houses on the street; size of nums
* Iterative Bottom Up: @Time: O(n) @Space: O(1)
*/

#include <algorithm>
#include <iostream>
#include <vector>

//Recursive Top Down
int memo(std::vector<int>& nums, int i, std::vector<int>& dp) {     
    if (i < 0) {
        return 0;
    }

    if (dp[i] >= 0) {
        return dp[i];
    }
            
    dp[i] = std::max(memo(nums, i-1, dp), memo(nums, i-2, dp) + nums[i]);
    
    return dp[i];
}

int rob(std::vector<int>& nums) {
    const int n = nums.size();

    std::vector<int> dp(n, -1);
    
    int maxLoot = memo(nums, n-1, dp);
    
    return maxLoot;
}

//Iterative Bottom Up
int rob(std::vector<int>& nums) {
    
    int twoDown = 0, maxLoot = 0;

    //For every house on the block a calculation occurs
    for (const auto& n : nums) {
        //Calculate max loot by looking at this house + two houses down
        //And the max $ looted thus far
        int calcLoot = std::max(n + twoDown, maxLoot);
        //Point to the house where curr. maxLoot is achieved
        twoDown = maxLoot;
        //If updating, point to house where the new maxLoot is achieved
        maxLoot = calcLoot;
    }

    return maxLoot;
}