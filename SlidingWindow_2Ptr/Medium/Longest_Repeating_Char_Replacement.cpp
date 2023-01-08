/**
* Alfredo Renteria
* Leetcode Problem #4324: Longest Repeating Character Replacement
* Leetcode 75 Level 1 - Medium
* @Topics: Hash Table, String, Sliding Window
* @Time: O(n) @Space: O(1)
* Where n is the length of s
*/

#include <algorithm>
#include <iostream>
#include <string>

//Sliding Window
int characterReplacement(std::string s, int k) {
    const int sLen = s.length();
    int start = 0, maxFreq = 0, longSubstrLen = 0;
    int freq[26] = {};
    
    for (int i = 0; i < sLen; i++) {
        freq[s[i] - 'A']++;
        maxFreq = std::max(maxFreq, freq[s[i] - 'A']);
        //Sliding window is invalid
        if (i + 1 - start - maxFreq > k) {
            //Update freq. of the outgoing element
            freq[s[start] - 'A']--;
            //Move start ptr. ahead by one step
            start++;
        }
        //Update longest substr length w/ sliding window
        longSubstrLen = i + 1 - start;
    }

    return longSubstrLen;
}