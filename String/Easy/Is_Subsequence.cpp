/**
* Alfredo Renteria
* Leetcode Problem #1392: Is Subsequence
* Leetcode 75 Level 1 - Easy
* @Topics: Two Pointers, String, Dynamic Programming
* @Time: O(n) @Space: O(1)
* Where n is the length of the input string
*/

#include <iostream>
#include <string>

//Recursive Method
bool isSubsequence(std::string s, std::string t) {
    //Empty string "" is always a subsequence
    if (s.empty()) {
        return true;
    //String 's' cannot be a subsequence if it has greater length than 't'
    } else if (s.length() > t.length()) {
        return false;
    }
    //Find the index of the first char. from 's' in 't'
    int pos = t.find(s[0]);
    //Char. from 's' is not in 't' --return false
    if (pos == std::string::npos) {
        return false;
    }
    //Char. from 's' is in 't' --recurse on the next chars. from 's' & 't'
    return isSubsequence(s.substr(1), t.substr(pos+1));
}