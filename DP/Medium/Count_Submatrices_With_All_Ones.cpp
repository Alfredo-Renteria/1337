/**
* Alfredo Renteria
* Leetcode Problem #1504: Count Submatrices With All Ones
* Mock OA- Medium
* @Topics: Array, Dynamic Programming, Stack, Matrix, Monotonic Stack
* @Time: O(m * n * m) @Space: O(m * n)
* Where m is the # of rows, and n is the # of columns in the matrix 
*/

#include <algorithm>
#include <limits>
#include <iostream>
#include <vector>

int subMat(std::vector<std::vector<int>>& mat) {
    //Get m X n matrix sizes
    int m = mat.size(), n = mat[0].size();
    //Intialize 2D vector that will hold the count of 1's
    std::vector<std::vector<int>> dp (m, std::vector<int>(n, 0));
    
    //Loop through the entire matrix searching for 1's
    for (int i = 0; i < m; i++) {
        //At every row, the count is reset
        int onesCount = 0;
        for (int j = 0; j < n; j++) {
            //When a 1 is found --increment the count
            if (mat[i][j] == 1) {
                onesCount++;
            //Otherwise; 0 is found --reset the count
            } else {
                onesCount = 0;
            }
            //Store the count of 1's found up to that position in our 2D vector
            dp[i][j] = onesCount;
        }
    }

    //Return variable for 'the # of submatrices that have all ones'
    int totalCount = 0;
    //Loop through the matrix again
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //This time at every column, we initialize a rectangle variable
            //Rectangle is set with maximum int value flag
            int rect = std::numeric_limits<int>::max();
            for (int k = i; k < m; k++) {
                //If a count of 0 is found at that [row][col] position
                //Rectangle will hold 0 value for the all subsequent rows
                rect = std::min(rect, dp[k][j]);
                //Combine rectangle to the total count
                totalCount += rect;
            }
        }
    }
    return totalCount;
}