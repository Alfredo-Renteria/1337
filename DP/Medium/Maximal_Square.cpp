/**
* Alfredo Renteria
* Leetcode Problem #221: Maximal Square
* Grind 75, Leetcode Dynamic Programming Level 1 - Medium
* @Topics: Array, Dynamic Programming, Matrix
* Bottom Up: @Time: O(m * n) @Space: O(m * n)
* Where m & n are the # of rows & columns respectively in nums
*/

#include <algorithm>
#include <iostream>

//Bottom Up Dynamic Programming
int maximalSquare(std::vector<std::vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    
    int dp[m + 1][n + 1], maxSqLen = 0;
    //Initiliaze dp matrix with zeroes
    std::fill(&dp[0][0], &dp[0][0] + (m + 1) * (n + 1), 0);
    
    //Traverse the matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            //If elem. is 1, update the min. square length that can be formed at that point
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                //Update max. square length
                maxSqLen = max(maxSqLen, dp[i][j]);
            } else {
                //Elem. is zero, min. square length is zero
                dp[i][j] = 0;
            }
        }
    }
    //Return result squared
    return maxSqLen * maxSqLen;
}