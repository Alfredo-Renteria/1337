/**
* Alfredo Renteria
* Leetcode Problem #62: Unique Paths
* Grind 75, Leetcode 75 Level 1 - Medium
* @Topics: Math, Dynamic Programming, Combinatorics
* Memoization Top Down: @Time: O(mn) @Space: O(mn)
* Tabulation Bottom Up: @Time: O(mn) @Space: O(n)
* Where m & n are the #s of rows & columns respectively
*/

#include <iostream>
#include <vector>

//Memoization Top Down
//Helper
int memo(int row, int col, std::vector<std::vector<int>>& dp){
    const int m = dp.size(), n = dp[0].size(); 
    
    if (row >= m || col >= n) {
        return 0;
    } else if (row == m-1 && col == n-1) {
        return 1;
    }

    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    
    return dp[row][col] = memo(row+1, col, dp) + memo(row, col+1, dp);
}
//Main    
int uniquePaths(int m, int n) {
    std::vector<vector<int>> dp(m, vector<int>(n,-1));
    
    return memo(0, 0, dp);
}

//Tabulation Bottom Up
int uniquePaths(int m, int n) {
    std::vector<int> paths(n, 1);
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            paths[j] += paths[j - 1];
        }
    }

    return paths[n - 1];
}