/**
* Alfredo Renteria
* Leetcode Problem #1657: Determine If Two Strings Are CLose
* December '22 LeetCoding Challenge - Medium
* @Topics: Hash Table, String, Sorting
* @Time: O(n logn) @Space: O(n)
* Where n is the # of characters in the string
* Time b/c of std::sort, Space b/c of containers.
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

bool closeStrings(std::string word1, std::string word2) {
    int w1Len = word1.length(), w2Len = word2.length();
    //Impossible to attain one word from the other in any # of operations
    if (w1Len != w2Len) {
        return false;
    }
    //Letters in the alphabet
    constexpr int alphCount = 26;
    //Arrays for each word's character count
    std::array<int, alphCount> charCount1 {}, charCount2 {};
    for (int i = 0; i < w1Len; i++) {
        charCount1[word1[i]-'a']++;
        charCount2[word2[i]-'a']++;
    }
    //Vectors for noting the letters present in each word
    std::vector<int> letrsPresent_a, letrsPresent_b;

    for (int i = 0; i < alphCount; i++) {
        if (charCount1[i]) {
            letrsPresent_a.push_back(i);
        }
        if (charCount2[i]) {
            letrsPresent_b.push_back(i);
        }
    }
    //Before checking if both words have similar character counts
    //First we make sure that similar letters are present
    if (letrsPresent_a != letrsPresent_b) {
        return false;
    }
    //Sort character count arrays in ascending order to aid comparison
    std::sort(charCount1.begin(), charCount1.end());
    std::sort(charCount2.begin(), charCount2.end());
    
    //Return true if character counts are the same, false otherwise
    return (charCount1 == charCount2);
}