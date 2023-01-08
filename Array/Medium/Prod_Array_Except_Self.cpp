/**
* Alfredo Renteria
* Leetcode Problem #238: Product Of Array Except Self
* Grind 75 - Medium
* @Topics: Array, Prefix Sum
* @Time: O(n) @Space: O(n)
* Where n is the size of nums
*/

#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    const int n = nums.size();
    std::vector<int> res(n, 1);

    for (int i = 1; i < n; i++) {
        res[i] = res[i-1] * nums[i-1];
    }

    int suffixProd = 1;
    for (int i = n-1; i >= 0; i--) {
        res[i] *= suffixProd;
        suffixProd *= nums[i];
    }

    return res;
}