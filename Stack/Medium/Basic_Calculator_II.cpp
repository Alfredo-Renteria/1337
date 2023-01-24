/**
* Alfredo Renteria
* Leetcode Problem #227: Basic Calculator II
* Grind 75, Leetcode 75 Level 2 - Medium
* @Topics: Math, String, Stack
* @Time: O(n) @Space: O(n)
* Where n is the length of the input string
*/

#include <iostream>
#include <stack>
#include <string>

int calculate(std::string s) {
    //Input string is empty, no calculations to compute --Return 0
    if (s.empty()) {
        return 0;
    }
    
    //For calculation operation characters -, +, *, /
    char operation = '+';
    int sLen = s.length();
    //For keeping track of the current number being operated on    
    int currNum = 0;
    //Stack that will assist with calculating the string expression
    std::stack<int> stack;
    
    for (int i = 0; i < sLen; i++) {
        //Current character of the string
        char currChar = s[i];
        
        //Character is a digit 0-9
        if (std::isdigit(currChar)) {
            currNum = (currNum * 10) + (currChar - '0');
        }

        //Character is a symbol OR curr. index is at the last elem. of the string
        if (!std::isdigit(currChar) && !std::iswspace(currChar) || i == sLen - 1) {
            //Subtraction op.
            //Prepend negative sign on curr. num. & push onto stack
            if (operation == '-') {
                stack.push(-currNum);

            //Addition op.
            //Just push curr. num. onto stack
            } else if (operation == '+') {
                stack.push(currNum);

            //Multiplication op.
            //Pop top value from the stack, multiply with curr. num.
            //& then push back onto stack    
            } else if (operation == '*') {
                int stackTop = stack.top();
                stack.pop();
                stack.push(stackTop * currNum);

            //Division op., similar to multiplication process
            } else if (operation == '/') {
                int stackTop = stack.top();
                stack.pop();
                stack.push(stackTop / currNum);
            }
           
            //Update operation symbol
            operation = currChar;
            //Reset current number
            currNum = 0;
        }
    }

    //For returning calculation answer
    int result = 0;

    //Accumulate all values from stack
    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
    
    //Return calculation
    return result;
}
