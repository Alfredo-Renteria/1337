/**
* Alfredo Renteria
* Leetcode Problem #2256: Minimum Average Difference
* December '22 LeetCoding Challenge - Medium
* @Topics: Array, Prefix Sum
* @Time: O(n) @Space: O(1)
* Where n is the # of elements in nums
*/

#include <cstdlib> //for abs
#include <iostream>
#include <limits> //for numeric_limits
#include <numeric> //for accumulate
#include <vector>

int minimumAverageDifference(std::vector<int>& nums) {
    //Get the total sum of the nums array
    long long total = std::accumulate(nums.begin(), nums.end(), 0LL);
    //Variable will hold the prefix sum as we loop through nums
    long long leftSum = 0LL;
    int min = std::numeric_limits<int>::max(), minIndex = 0;
    const int n = nums.size();

    for (int i = 0; i < n; i++) {
        //Update prefix sum
        leftSum += nums[i];
        //Calculate average of the left part of nums
        //+1 to account for 0-indexed
        int leftavg = leftSum / (i+1);
        //Now calculate the right part
        //When we reach i = n-1, assign 0 to prevent division by 0 error
        int rightavg = (n-i-1 == 0) ? 0 : (total-leftSum) / (n-i-1);
        //Finally, calculate the difference of averages
        int avgDiff = std::abs(leftavg - rightavg);
        //If current difference is less than registered minimum difference
        if (avgDiff < min) {
            //Reassign minimum difference and log the index
            min = avgDiff;
            minIndex = i;
        }
    }
    return minIndex;
}