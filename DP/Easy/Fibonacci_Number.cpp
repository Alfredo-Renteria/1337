/**
* Alfredo Renteria
* Leetcode Problem #509: Fibonacci Number
* Leetcode 75 Level 1 - Easy
* @Topics: Math, DP, Recursion, Memoization
* Math: @Time: O(1) @Space: O(1)
* Recursive: @Time: O(2^n) @Space: O(n)
* Bottom Up: @Time: O(n) @Space: O(1)
* Tabulation: @Time: O(n) @Space: O(n)
* Memoization: @Time: O(n) @Space: O(n)
* Where n is the total fibonacci #s
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

//Math - Using Binet's Formula
//Works w/ constraints: 0 <= n <= 30
int fib(int n) {
    const double phi = (std::sqrt(5) + 1) / 2;     
    
    return std::round(std::pow(phi, n) / std::sqrt(5));
}

//Recursive
int fib(int n) {
    if (n < 2) {
        return n;
    }
    
    return fib(n-1) + fib(n-2);
}

//Iterative Bottom Up
int fib(int n) {
    if (n < 2) { 
        return n;
    }
	
    int a = 1, b = 1;

    for (int i = 2; i < n; i++) {
        a += b;
        std::swap(a, b);
    }

    return b;
}

//Tabulation - Iterative Bottom Up
int fib(int n) {
  if (n < 2) {
      return n;
  }

  static std::vector<int> dp = {0, 1};
  for (int i = 2; i < n + 1; i++) {
      dp.push_back(dp[i - 1] + dp[i - 2]);
  }

  return dp[n];
}

//Memoization - Recursive Top Down
//Helper
int fib_calc(int n, std::vector<int>& dp) {
    if (n < 2) {
        return n;
    }

    if (dp[n] != 0) {
        return dp[n];
    }
    
    dp[n] = fib_calc(n-1, dp) + fib_calc(n-2, dp);
    
    return dp[n];
}

//Main
int fib(int n) {
    std::vector<int> dp(n+1,0);
    
    return fib_calc(n, dp);
}