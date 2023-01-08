/**
* Alfredo Renteria
* Leetcode Problem #739: Daily Temperatures
* December '22 LeetCoding Challenge - Medium
* @Topics: Array, Stack, Monotonic Stack
* @Time: O(n) @Space: O(n)
* Where n is the size of temps
*/

#include <iostream>
#include <stack>
#include <vector>

std::vector<int> dailyTemperatures(std::vector<int>& temps) {
    const int n = temps.size();
    
    std::stack<int> s;
    
    std::vector<int> result(n);
    
    for (int i = n-1; i >= 0; i--) {
        while (!s.empty() && temps[s.top()] <= temps[i]) {
            s.pop();
        }
        
        if (s.empty()) {
            result[i] = 0;
        } else {
            result[i] = s.top() - i;
        }

        s.push(i);
    }
    return result;
}