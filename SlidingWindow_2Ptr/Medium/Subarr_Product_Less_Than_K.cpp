/**
* Alfredo Renteria
* Leetcode Problem #713: Subarray Product Less Than K
* Algorithm Level 2 - Medium
* @Topics: Array, Sliding Window
* @Time: O(n) @Space: O(1)
* Where n is the size of nums
*/

#include <iostream>
#include <vector>

//Sliding Window
int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    const int n = nums.size();
    
    if (k <= 1) {
        return 0;
    }

    int prod = 1, subArrsTotal = 0, start = 0;
    
    for (int i = 0; i < n; i++) {
        prod *= nums[i];
        //Prod is not strictly less than k
        while (prod >= k) {
            //Divide prod w/ elem. at window start, then move start by one
            prod /= nums[start++];
        }
        //Accumulate sub arrs. from window
        subArrsTotal += i - start + 1;
    }

    return subArrsTotal;
}