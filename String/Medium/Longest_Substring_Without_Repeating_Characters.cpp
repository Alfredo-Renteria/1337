
/**
* Alfredo Renteria
* Leetcode Problem #3: Longest Substring Without Repeating Characters
* Grind 75 - Medium
* @Topics: Hash Table, String, Sliding Window
* @Time: O(n) @Space: O(min(m,n))
* Where n is the length of s
* And m is the size of the charset/alphabet used in the string
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
    //Chars. from input string map to 1-index pos. ahead of their location
    std::unordered_map<char, int> map;
    const int sLen = s.length();
    int maxLen = 0, start = 0;
    for (int i = 0; i < sLen; i++) {
        //Character is already in the map
        //'Start' may be updated if mapped char. has greater index
        if (map.find(s[i]) != map.end()) {
            start = std::max(start, map[s[i]]);
        }
        maxLen = std::max(maxLen, i - start + 1);
        //Update character mapping
        map[s[i]] = i + 1;
    }
    return maxLen;
}