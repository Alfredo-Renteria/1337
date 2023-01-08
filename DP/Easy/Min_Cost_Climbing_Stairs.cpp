/**
* Alfredo Renteria
* Leetcode Problem #746: Min Cost Climbing Stairs
* Leetcode 75 Level 1 - Easy
* @Topics: Array, DP
* Bottom Up: @Time: O(n) @Space: O(n)
* Where n is the size of cost; # of steps
*/

#include <algorithm>
#include <iostream>
#include <vector>

//Tabulation - Iterative Bottom Up
int minCostClimbingStairs(std::vector<int>& cost) {
    const int n = cost.size();
    
    std::vector<int> dp(n+1);
    
    for (int i = 2; i < n + 1; i++) {
        dp[i] = std::min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
    }
    
    return dp[n];
}