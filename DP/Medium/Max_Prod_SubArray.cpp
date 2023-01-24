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
    //Vectors hold min and max products at i
    std::vector<int> dpMin(nums), dpMax(nums);
    //Initialize return variable with the 1st elem. of nums
    int ans = nums[0];
    
    for (int i = 1; i < n; i++) {
        int minProd = 0, maxProd = 0;
        //If num is positive
        if (nums[i] >= 0) {
            minProd = std::min(nums[i], nums[i] * dpMin[i-1]);
            maxProd = std::max(nums[i], nums[i] * dpMax[i-1]);
        //Else, num is negative
        } else {
            minProd = std::min(nums[i], nums[i] * dpMax[i-1]);
            maxProd = std::max(nums[i], nums[i] * dpMin[i-1]);
        }
        dpMin[i] = minProd;
        dpMax[i] = maxProd;

        ans = std::max(ans, dpMax[i]);
    }

    return ans;
}