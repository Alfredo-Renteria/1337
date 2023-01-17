/**
* Alfredo Renteria
* Leetcode Problem #409: Longest Palindrome
* Grind75 - Leetcode 75 Level 1 - Easy
* @Topics: Hash Table, String, Greedy
* @Time: O(n) @Space: O(1)
* Where n is the length of s
* Space: O(1) b/c the alphabet size of s is fixed
*/

#include <iostream>
#include <string>

int longestPalindrome(std::string s) {
    //Initialize array to fit ascii table
    int count[128] = {}, palLen = 0;
    
    //Get the letter counts
    for (const char& c : s) {
        count[c]++;
    }
    
    for (const int& c : count) {
        //Palindrome length only accumulates even counts
        palLen += c/2 * 2;
        //The first time we see an odd count for a respective letter
        //Increment palindrome length by 1
        //Note: length will only meet even condition for the 1st odd count
        if (palLen % 2 == 0 && c % 2 == 1) {
            palLen++;
        }
    }

    return palLen;
}