/**
* Alfredo Renteria
* Leetcode Problem #70: Climbing Stairs
* December '22 LeetCoding Challenge - Easy
* @Topics: Math, Dynamic Programming, Memoization
* Memoization: @Time: O(n) @Space: O(n)
* Where n are the # of steps
*/

#include <iostream>
#include <unordered_map>
#include <vector>

//Memoization - Recursive Top Down w/ std::unordered_map
//Helper
int fib(int n, std::unordered_map<int,int>& m) {
    if (n <= 2) {
        return n;
    }

    if (m.find(n) != m.end()) {
        return m[n];
    }

    m[n] = fib(n-1, m) + fib(n-2, m);
    
    return m[n];
}
//Main
int climbStairs(int n) {
    std::unordered_map<int,int> m;
    
    return fib(n, m);
}

//Memoization - Recursive Top Down w/ std::vector
int distinctWays(int n, std::vector<int>& dp) {
    if (n <= 2) {
        return n;
    }
    
    if (dp[n] != 0) {
        return dp[n];
    }
    
    dp[n] = distinctWays(n-1, dp) + distinctWays(n-2, dp);
    
    return dp[n];
}

int climbStairs(int n) {
    std::vector<int> dp(n+1, 0);
    
    return distinctWays(n, dp);
}