/**
* Alfredo Renteria
* Leetcode Problem #53: Maximum Subarray
* Grind 75, Leetcode Dynamic Programming Level 1 - Medium
* @Topics: Array, Divide and Conquer, Dynamic Programming
* Bottom Up: @Time: O(n) @Space: O(n)
* Where n is the size of nums
*/

#include <iostream>
#include <vector>

//Bottom Up Dynamic Programming
int maxSubArray(std::vector<int>& nums) {
    const int n = nums.size();
    
    std::vector<int> dp(nums);
    
    for (int i = 1; i < n; i++) {
        dp[i] = max(nums[i], nums[i] + dp[i-1]);
    }

    return *max_element(dp.begin(), dp.end());
}
