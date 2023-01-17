/**
* Alfredo Renteria
* Leetcode Problem #14: Longest Common Prefix
* Leetcode 75 Level 2 - Easy
* @Topics: String
* Binary Search: @Time: O(S*logm) @Space: O(p)
* Where m is the max length of a string in strs, and n is the size of strs
* S is the sum of all characters from all strings in strs; m*n
* And p is the min length of a string in strs
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//Binary Search
//Helper
bool isCommonPrefix(std::vector<std::string>& strs, int mid) {
    int n = strs.size();
    std::string firstWord = strs[0].substr(0, mid);

    //Starting from the second word in strs up to the last
    for (int i = 1; i < n; i++) {
        //Get the current word
        std::string temp = strs[i].substr(0, mid);
        //Comparing curr. word and the first word for mid length chars.
        //If strings don't match -- return false
        if (temp.compare(firstWord) != 0) {
            return false;
        }
    }
    //There is a common prefix for mid length chars.
    return true;
}

//Main
std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string minStr = *min_element(strs.begin(), strs.end());
    //Right value will be equal to the length of the smallest string in strs
    int left = 1, right = minStr.length(), lcpLen = 0;

    while (left <= right) {
        int mid = (left + right) >> 1;
        if (isCommonPrefix(strs, mid)) {
            lcpLen = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    return strs[0].substr(0, lcpLen);
}