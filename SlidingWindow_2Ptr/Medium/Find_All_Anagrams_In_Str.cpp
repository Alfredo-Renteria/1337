/**
* Alfredo Renteria
* Leetcode Problem #438: Find All Anagrams In A String
* Grind 75, Leetcode 75 Level 1 - Medium
* @Topics: Hash Table, String, Sliding Window
* @Time: O(n) @Space: O(n)
* Where n is the length of s
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//Sliding Window
std::vector<int> findAnagrams(std::string s, std::string p) {
    const int sLen = s.length(), pLen = p.length();

    //String s is too small to contain p's anagrams
    if (sLen < pLen) {
        return {};
    }
    
    //To keep chars. count in p & s
    int freq_p[26] = {}, window[26]= {};
    
    for (int i = 0; i < pLen; i++) {
        freq_p[p[i] - 'a']++;
        window[s[i] - 'a']++;
    }

    std::vector<int> indices;
    //First window has p's anagrams
    if (std::equal(freq_p, end(freq_p), window)) {
        indices.push_back(0);
    }
    //From the end of the first window through the remainder of string s
    for (int i = pLen; i < sLen; i++) {
        //Decrement char. count of elem. to the left of window start
        window[s[i-pLen] - 'a']--;
        //Increment char. count of elem. at the end of the window (inclusive)
        window[s[i] - 'a']++;
        //Another window has p's anagram, insert start index
        if (std::equal(freq_p, end(freq_p), window)) {
            indices.push_back(i-pLen+1);
        }
    }

    return indices;
}