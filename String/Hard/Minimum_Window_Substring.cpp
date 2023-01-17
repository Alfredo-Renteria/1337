/**
* Alfredo Renteria
* Leetcode Problem #76: Minimum Window Substring
* Grind 75 - Hard
* @Topics: Hash Table, String, Sliding Window
* @Time: O(|S|+|T|) @Space: O(|S|+|T|)
* Where |S| & |T| are the lengths of s & t
*/

#include <iostream>
#include <limits>
#include <string>

void foundCharsFromT(int charCount, int& charsToWorkWith, int manip) {
    if (charCount > 0) {
        charsToWorkWith += manip;
    }
}

std::string minWindow(std::string s, std::string t) {
    int m = s.length(), n = t.length();
    //Cannot derive a window from 's' -- return empty string
    if (m < n) return "";

    //Array will store count of characters
    int charCount[123] = {0};
    //Get count of characters in 't'
    for (const auto& c : t) {
        charCount[c]++;
    }

    int start = 0, end = 0;
    int len = std::numeric_limits<int>::max();

    for (int i = 0; i < m; i++) {
        //If char. from 't' has positive count, n; charsToWorkWith is reduced
        foundCharsFromT(charCount[s[i]], n, -1);
        //Decrement the count of char. at 's[i]'
        charCount[s[i]]--;
        //Enter loop when there are no characters from 't' to work with
        //--Controlled by foundCharsFromT helper function
        while (n == 0) {
            //If we find a new minimum window than the current one
            if (len > i - end + 1) {
                //Readjust length accordingly
                len = i - end + 1;
                //Set start to the end cursor -- to potentially find more
                start = end;
            }
            //Increase the count of char. at 's[end]'
            charCount[s[end]]++;
            //If char. from 't' has positive count, n; charsToWorkWith is increased
            foundCharsFromT(charCount[s[end]], n, 1);
            //Move the end cursor along
            end++;
        }
    }
    //If len was never altered -- return empty string
    //Else -- return string containing chars. from s[start] to s[len]
    return (len == std::numeric_limits<int>::max()) ? "" : s.substr(start,len);
}