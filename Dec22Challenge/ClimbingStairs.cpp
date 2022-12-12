/**
* Alfredo Renteria
* Leetcode Problem #70: Climbing Stairs
* December '22 LeetCoding Challenge - Easy
* @Topics: Math, Dynamic Programming, Memoization
* @Time: O(n) @Space: O(n)
* Where n are the # of steps
*/

#include <iostream>
#include <unordered_map>

int fib(int n, std::unordered_map<int,int>& m) {
    //First two ifs are base cases:
    //For negative steps, there are 0 distinct ways to climb to the top
    if (n < 0) {
        return 0;
    //For zero steps, there is 1 distinct way, not moving
    } else if (n == 0) {
        return 1;
    //If we have calculation for n, retrieve it -- memoization
    } else if (m.find(n) != m.end()) {
        return m[n];
    }
    //Else calculate for n steps by recursing on n-1 & n-2
    m[n] = fib(n-1, m) + fib(n-2, m);
    return m[n];
}

int climbStairs(int n) {
    std::unordered_map<int,int> m;
    //Return # of distinct ways
    return fib(n, m);
}