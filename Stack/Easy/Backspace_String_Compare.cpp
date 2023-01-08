/**
* Alfredo Renteria
* Leetcode Problem #844: Backspace String Compare
* Leetcode 75 Level 1 - Easy
* @Topics: Two Pointers, String, Stack, Simulation
* Stack: @Time: O(m + n) @Space: O(m + n)
* Where m & n are the lengths of s & t respectively
* Two Pointers: @Time: O(m + n) @Space: O(1)
*/

#include <iostream>
#include <string>

//Stack
std::string reducedStr(const std::string& str) {
  const int str_len = str.length();
  int bkspcCount = 0;
  std::string new_str = "";
  for (int i = str_len-1; i >= 0; i--) {
    if (str[i] == '#') {
      bkspcCount++;
    } else if (bkspcCount > 0) {
      bkspcCount--;
    } else
      new_str += str[i];
  }
  
  return new_str;
}
  
bool backspaceCompare(std::string s, std::string t) {
  return reducedStr(s) == reducedStr(t);
}

//Two Pointers
int reducedStr2(std::string& s) {
    int size = 0, bkspcCount = 0, pos = s.length() - 1;
    for (int i = pos; i >= 0; i--) {
        if (s[i] == '#') {
            bkspcCount++;
        } else { 
            if (bkspcCount <= 0) {
                s[pos--] = s[i];
                size++;
            } else {
                bkspcCount--;
            }
        }
    }
    
    return size;
}

bool backspaceCompare(std::string s, std::string t) {
    const int sLen = s.length(), tLen = t.length();
    
    int sizeA = reducedStr2(s), sizeB = reducedStr2(t);
    
    if (sizeA != sizeB) {
        return false;
    }
    
    int j = sLen - 1, k = tLen - 1;
    for (int i = 0; i < sizeA; i++) {
        if (s[j--] != t[k--]) {
          return false;
        }
    }
    return true;
}