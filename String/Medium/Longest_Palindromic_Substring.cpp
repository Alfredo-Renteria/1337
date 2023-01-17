/**
* Alfredo Renteria
* Leetcode Problem #5: Longest Palindromic String
* Grind 75 - Medium
* @Topics: String, Dynamic Programming
* @Time: O(n^2) @Space: O(1)
* Where n is the length of s
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//Expand around the center --helper function
int expandATC(std::string& s, int left, int right) {
    const int sLen = s.length();
    //Left & right ptrs. are within bounds & are pointing at the same character
    while (left >= 0 && right < sLen && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

std::string longestPalindrome(std::string s) {
    const int sLen = s.length();
    //When a longest palindrome is found:
    //'Start' marks the beginning index of the substring
    //'End' notes the length; # of characters to include in the substring
    int start = 0, end = 0;
    for (int i = 0; i < sLen; i++) {
        int len = std::max(expandATC(s, i, i), expandATC(s, i, i+1));
        if (len > end) {
            end = len;
            start = i - (len-1)/2;
        }
    }
    return s.substr(start, end);
}