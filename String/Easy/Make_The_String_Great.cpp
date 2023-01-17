
/**
* Alfredo Renteria
* Leetcode Problem #1544: Make The String Great
* Easy
* @Topics: String, Stack
* @Time: O(n) @Space: O(n)
* Where n is the length of the input string
*/

#include <cmath>
#include <iostream>
#include <string>

std::string makeGood(std::string s) {
    //Absolute diff. value b/n upper and lower cases, or vice-versa in ASCII
    const int asciiDiff = 32;
    //Return string will be operable like a stack
    std::string goodStr = "";
    for (const auto& c : s) {
        //Current char. and the char. from top of stack are the same letter
        //But in upper-case or lowercase --pop char. from stack
        if (!goodStr.empty() && std::abs(goodStr.back() - c) == asciiDiff) {
            goodStr.pop_back();
        } else {
            //Add to stack
            goodStr.push_back(c);
        }
    }
    return goodStr;
}