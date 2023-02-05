/**
* Alfredo Renteria
* Leetcode Problem #152: Maximum Product Subarray
* Grind 75, Leetcode 75 Level 2 - Medium
* @Topics: Array, Dynamic Programming
* Iterative Bottom Up: @Time: O(n) @Space: O(n)
* Where n is the size of nums
*/

#include <algorithm>
#include <iostream>
#include <vector>

//Iterative Bottom Up
int maxProduct(std::vector<int>& nums) {
    const int n = nums.size();
    //Initialize return variable with the 1st elem. of nums
    int ans = nums[0];
    //Vectors hold min and max products at i
    std::vector<int> dpMin(nums), dpMax(nums);
    
    for (int i = 1; i < n; i++) {
        //If num is positive
        if (nums[i] >= 0) {
            dpMin[i] = std::min(nums[i], nums[i] * dpMin[i-1]);
            dpMax[i] = std::max(nums[i], nums[i] * dpMax[i-1]);
        //Else, num is negative
        } else {
            dpMin[i] = std::min(nums[i], nums[i] * dpMax[i-1]);
            dpMax[i] = std::max(nums[i], nums[i] * dpMin[i-1]);
        }

        ans = std::max(ans, dpMax[i]);
    }

    return ans;
}