/**
* Alfredo Renteria
* Leetcode Problem #224: Basic Calculator
* Grind 75 - Hard
* @Topics: Math, String, Stack, Recursion
* @Time: O(n) @Space: O(n)
* Where n is the length of the string expression
*/

#include <iostream>
#include <stack>
#include <string>

int calculate(std::string s) {
    //Init. stack to hold expressions: '0'-'9', '+', '-', '(', ')', & ' '
    std::stack<int> st;
    //Init. return variable & sign defaulted to positive
    int ans = 0, sign = 1, sLen = s.length();

    for (int i = 0; i < sLen; i++) {
        //If char. at 's[i]' is a digit; '0'-'9'
        if (std::isdigit(s[i])) {
            //Init. number value variable
            int val = 0;
            //If there are digits neighboring 's[i]' -- build the number
            while (std::isdigit(s[i])) {
                val *= 10;
                val += s[i] - '0';
                i++;
            }
            //Multiply number with sign and add to result
            ans += val * sign;
            //Reset sign to default -- positive
            sign = 1;
            //Decrement index, b/c while loop exited one position over
            i--;
        //Open parenthesis case
        } else if (s[i] == '(') {
            //Push current result to stack
            st.push(ans);
            //& the current sign as well
            st.push(sign);
            //Reset both result and sign
            ans = 0;
            sign = 1;
        //Closed parenthesis case
        } else if (s[i] == ')') {
            //Multiply current result w/ sign from stack
            ans *= st.top();
            st.pop();
            //Add result from stack to current result
            ans += st.top();
            st.pop();
        //Unary negation operator
        } else if (s[i] == '-') {
            //Invert sign -- negative
            sign = -1;
        }
    }
    return ans;
}