/**
* Alfredo Renteria
* Leetcode Problem #1: Two Sum
* Grind 75, Leetcode 75 Level 1 - Easy
* @Topics: Array, Hash Table
* @Time: O(n) @Space: O(n)
* Where n is the size of nums
*/

#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    const int n = nums.size();
    //Map will store remainder as key & index as value
    std::unordered_map<int,int> map;
    
    for (int i = 0; i < n; i++) {
        //When remainder key is found; curr. element is equal to remainder
        if (map.find(nums[i]) != map.end()) {
            return {map[nums[i]], i};
        } else {
            map[target - nums[i]] = i;
        }
    }
    
    return {-1, -1};
}