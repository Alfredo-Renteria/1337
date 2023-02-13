/**
* Alfredo Renteria
* Leetcode Problem #17: Letter Combinations Of A Phone Number
* Grind 75,  - Medium
* @Topics: Hash Table, String, Backtracking
* BackTracking + Hash Table: @Time: O(4^n) @Space: O(4^n)
* Where n is the length of digits
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty()) {
        return {};
    }
    //Map each digit to the its corresponding letter combo
    std::unordered_map<char, std::string> phoneMap;
    phoneMap.insert( { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"} } );
    phoneMap.insert( { {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} } );         
    
    //Return std::vector to store all letter combinations
    std::vector<std::string> res;
    
    //To store current combination
    std::string temp = "";
    
    generateCombos(digits, 0, temp, res, phoneMap);
    
    return res;
}

void generateCombos(std::string& digits, int i, std::string& temp, std::vector<std::string>& res, unordered_map<char, std::string>& map) {
    const int n = digits.length();
    
    //All digits have been processed, add the curr. combo to the result std::vector
    if (i == n) {
        res.push_back(temp);
        return;
    }
    //Loop through all letters corresponding to the curr. digit
    for (const auto& letter : map[digits[i]]) {
        //Add curr. letter to temp str.
        temp.push_back(letter);
        //Recursively generate combos for the remaining digits
        generateCombos(digits, i + 1, temp, res, map);
        //Remove the last char from temp str. to generate other combos 
        temp.pop_back();
    }
}