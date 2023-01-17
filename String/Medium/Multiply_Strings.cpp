/**
* Alfredo Renteria
* Leetcode Problem #43: Multiply Strings
* Leetcode 75 Level 2 - Medium
* @Topics: Math, String, Simulation
* @Time: O(m*n) @Space: O(m+n)
* Where m & n ares the lengths of strings num1 & num2 respectively
*/

#include <algorithm>
#include <iostream>
#include <string>

std::string multiply(std::string num1, std::string num2) {
    const int n1 = num1.length(), n2 = num2.length();
    const char zero = '0';

    //Strings start w/ zero -- base case
    if (num1.front() == zero || num2.front() == zero) {
        return {zero};
    }
    
    //Init. return str.
    std::string answer(n1 + n2, zero);
    
    //Starting from the end of the strings
    for (int i = n2 - 1; i >= 0; i--) {
        int digit2 = num2[i] - zero;
        
        for (int j = n1 - 1; j >= 0; j--) {
            int digit1 = num1[j] - zero;
            
            //Figure place value by indices
            int numZeros = ((n1 - 1) - j) + ((n2 - 1) - i);
            int carry = answer[numZeros] - zero;
            int mult = digit1 * digit2 + carry;
            
            //Store results & carry
            answer[numZeros] = (mult % 10) + zero;
            answer[numZeros + 1] += (mult / 10);
        }
    }

    //Return string cannot lead w/ zero; check prior to reversing
    if (answer.back() == zero) {
        answer.pop_back();
    }

    std::reverse(answer.begin(), answer.end());
    
    return answer;
}