/**
* Alfredo Renteria
* Leetcode Problem #74: Search a 2D Matrix
* Grind 75, Leetcode 75 Level 2 - Medium
* @Topics: Array, Binary Search, Matrix
* @Time: O(log(m * n) @Space: O(1)
* Where m ia the # of rows in the matrix, and n is the # of columns
*/

#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    //Get nRows and nColumns
    int m = matrix.size(), n = matrix[0].size();
    //Assign left and right - Binary Search
    int left = 0, right = m * n - 1;
    
    while (left <= right) {
        int mid = left + (right-left)/2;
        //Calculate row and col coords. of the mid elem.
        int row = mid / n, col = mid % n;
        
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

