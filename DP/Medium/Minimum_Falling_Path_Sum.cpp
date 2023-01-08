/**
* Alfredo Renteria
* Leetcode Problem #931: Minimum Falling Path Sum
* December '22 LeetCoding Challenge - Medium
* @Topics: Array, Dynamic Programming, Matrix
* Top Down: @Time: O(n^2) @Space: O(1)
* Bottom Up: @Time: O(n^2) @Space: O(n)
* Where n is the length of the matrix; since matrix is n*n
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

//Inplace Dynamic Programming Memoization - Top Down
int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
    constexpr int maxVal = std::numeric_limits<int>::max();
    int n = matrix.size();
    //Starting from the 2nd row, loop through every row in the matrix
    for (int r = 1; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int left, right;
            //When evaluating the 1st column of a new row
            //Make left hold max so it is not considered --out of bounds
            if (c == 0) {
                left = maxVal;
            } else {
                //Get left diagonal from current position
                left = matrix[r-1][c-1];
            }
            //When at the last column, similar handling to 1st col. case above
            if (c == n-1) {
                right = maxVal;
            } else {
                //Right diagonal
                right = matrix[r-1][c+1];
            }
            //Update minimum sum path for this position
            //Considering left & right diagonals, & directly above
            matrix[r][c] += std::min({left, matrix[r-1][c], right});
        }
    }
    return *std::min_element(matrix.back().begin(), matrix.back().end());
}

//Dynamic Programming Tabulation - Bottom Up
int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
    //Initialize dp vector with the 1st row from the matrix
    std::vector<int> dp = matrix[0];
    int n = matrix.size(), lc = n-1;
    
    //Starting from the 2nd row, loop through every row in the matrix
    //Updating the minimum sum of any falling path
    for (int r = 1; r < n; r++) {
        //Initialize solution vector with current dp
        std::vector<int> sol = dp;
        
        //1st column:
        //|   [0]  |   [1]  |  ...  |  [lc]  |   --dp
        //| [r][0] |  ...   |  ...  |  [lc]  |   --matrix        
        sol[0] = matrix[r][0] + std::min({dp[0], dp[1]});
        
        //For every col., after the 1st([fc]) & before the last([lc]):
        //| [fc] | [c-1] |   [c]  | [c+1] | ... | [lc] |   --dp
        //| [fc] |  ...  | [r][c] |  -->  | ... | [lc] |   --matrix
        for (int c = 1; c < lc; c++) {
            sol[c] = matrix[r][c] + std::min({dp[c - 1], dp[c], dp[c + 1]});
        }

        //Last column:
        //| [fc] |  ...  | [lc-1] |   [lc]   |   --dp
        //| [fc] |  ...  |   ...  | [r][lc]  |   --matrix
        sol[lc] = matrix[r][lc] + std::min({dp[lc], dp[lc - 1]});
        
        //Update dp
        dp = sol;
    }
    
    return *std::min_element(dp.begin(), dp.end());
}