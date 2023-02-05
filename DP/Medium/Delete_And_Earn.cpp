/**
* Alfredo Renteria
* Leetcode Problem #740: Delete And Earn
* Leetcode Dynamic Programming Level 1 - Medium
* @Topics: Array, Hash Table, Dynamic Programming
* Bottom Up + Map: @Time: O(n * logn) @Space: O(n)
* Where n is the size of nums
*/

#include <algorithm>
#include <iostream>
#include <vector>

//Bottom Up + Map
int deleteAndEarn(vector<int>& nums) {        
    //To map points value count in nums
    std::unordered_map<int, int> count;
    //Get count
    for (const auto& n : nums) {
        count[n]++;
    }

    //Sort the points in ascending order
    std::sort(nums.begin(), nums.end());
    //Get rid of duplicate point values in nums
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    
    //New size of nums
    int newN = nums.size();
    //Initialize earn aggregators to zero
    int earn1 = 0, earn2 = 0;
    //For every point value
    for (int i = 0; i < newN; i++) {
        //Placehold earn2 sum
        int temp = earn2;
        //Calculate current points possible
        int currEarn = nums[i] * count[nums[i]];
        //Index is above 1st pos. AND the last point value cannot be counted
        if (i > 0 && nums[i-1] == (nums[i] - 1)) {
            //Update earn2 with max points value
            earn2 = max(currEarn + earn1, earn2);
            //Update earn1 to last earn2
            earn1 = temp;
        } else {
            //Update earn2 with sum of current points possible
            earn2 += currEarn;
            earn1 = temp;
        }
    }

    //Return max. # of points
    return earn2;
}