/**
* Alfredo Renteria
* Leetcode Problem #704: Binary Search
* Grind 75, Leetcode 75 Level 1 - Easy
* @Topics: Array, Binary Search
* @Time: O(logn) @Space: O(1)
* Where n is the size of nums
*/

#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    while (low <= high) {
        int mid = low + high-low/2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}