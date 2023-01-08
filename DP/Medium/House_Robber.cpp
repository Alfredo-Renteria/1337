/**
* Alfredo Renteria
* Leetcode Problem #198: House Robber
* December '22 LeetCoding Challenge - Medium
* @Topics: Array, Dynamic Programming
* @Time: O(n) @Space: O(1)
* Where n are the # of houses on the street; size of nums
*/

#include <algorithm>
#include <iostream>

int rob(vector<int>& nums) {
    //'Heist1' holds the max $ robbed up to & including the 2nd from last home
    //'Heist2' goes up to the last home
    int heist1 = 0, heist2 = 0;
    for (const auto& n : nums) {
        int maxLoot = std::max(n + heist1, heist2);
        heist1 = heist2;
        heist2 = maxLoot;
    }
    return heist2;
}