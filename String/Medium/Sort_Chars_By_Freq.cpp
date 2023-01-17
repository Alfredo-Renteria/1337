/**
* Alfredo Renteria
* Leetcode Problem #451: Sort Characters By Frequency
* December '22 LeetCoding Challenge - Medium
* @Topics: Hash Table, String, Sorting, Heap(Priority Queue),
*          Bucket Sort, Counting
* @Time: O(n logn) @Space: O(n)
* Where n is the length of s
* Time: b/c of std::sort, Space: b/c of containers.
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

std::string frequency(std::string s) {
    constexpr int asciiRange = 75;
    //Vector of pair ints is size 75; ascii range from '0' to 'z'
    //First int holds the count, the second is for the char.
    std::vector<std::pair<int,int>> charCount(asciiRange);
    for (const auto& c : s) {
        int count = charCount[c-'0'].first;
        if (!count) {
            charCount[c-'0'] = std::make_pair(++count, c-'0');
        } else {
            charCount[c-'0'].first = ++count;
        }
    }
    //Sort vector in descending order, so highest freq. char. appears first
    std::sort(charCount.begin(), charCount.end(), std::greater<>());

    std::string res = "";
    for (auto& i : charCount) {
        int count = i.first;
        //If count exists, add chars. to string result
        while (count) {
            res.push_back(i.second+'0');
            count--;
        }
    }
    return res;
}