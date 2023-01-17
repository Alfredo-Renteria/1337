/**
* Alfredo Renteria
* Leetcode Problem #1704: Determine If String Halves Are Alike
* December '22 LeetCoding Challenge - Easy
* @Topics: String, Counting
* @Time: O(n) @Space: O(n)
* Where n is the length of s
*/

#include <iostream>
#include <string>

//Counts vowels in the given string 's' and returns the total count
int vowelCount(std::string s) {
    //ASCII values for vowels offset by 'a'
    constexpr int a = 0, e = 4, i = 8, o = 14, u = 20;
    int count = 0;

    for (const auto&c : s) {
        //Calculate once
        char asciiVal = c - 'a';
        if (asciiVal == a) {
            count++;
        } else if (asciiVal == e) {
            count++;
        } else if (asciiVal == i) {
            count++;
        } else if (asciiVal == o) {
            count++;
        } else if (asciiVal == u) {
            count++;
        }
    }
    return count;
}

//Split the given string 's' of even length into 'a' & 'b'
//Returns true if both 'a' & 'b' are alike
//Strings are alike if they have the same # of vowels
bool halvesAreAlike(std::string s) {
    const int sLen = s.length();
    //Lowercase every characet in 's'
    for (int i = 0; i < sLen; i++) {
        s[i] = std::tolower(s[i]);
    }

    /*
    //Can also be achieved w/ 'for_each' & 'transform' from <algorithm>:
    std::for_each(s.begin(), s.end(), [](char& c){ c = std::tolower(c); });
    std::transform(s.cbegin(), s.cend(), 
                   s.begin(), 
                   [](char c){ return std::tolower(c); });
    */

    //String is even, so no issues with divsion by 2
    std::string a(s.begin(), s.begin() + (sLen / 2));
    std::string b(s.begin() + (sLen / 2), s.end());

    return vowelCount(a) == vowelCount(b);
}