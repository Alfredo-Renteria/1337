/**
* Alfredo Renteria
* Leetcode Problem #1143: Longest Common Subsequence
* December '22 LeetCoding Challenge - Medium
* @Topics: String, Dynamic Programming
* @Time: O(n*m) @Space: O(n*m)
* Where n & m are the lengths of text1 & text2 respectively
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//Dynamic Programming Tabulation - Bottom Up
int longestCommonSubsequence(std::string text1, std::string text2) {
    int n = text1.length(), m = text2.length();
    //Int array that will note longest common subsequence from the bottom up
    int dp[n+1][m+1];
    //Fill array with 0's
    std::fill(&dp[0][0], &dp[0][0] + (n+1)*(m+1), 0);
    //Rows represent text1 length + 1, and columns text2 length + 1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //When characters in both strings match, from the current position
            //Increment the count from top left diagonal in dp
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
            //Else, characters don't match, then from the current position
            //Get the max count between the left & top elements in dp    
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    //Return the last element in dp
    return dp[n][m];
}