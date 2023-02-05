/**
* Alfredo Renteria
* Leetcode Problem #73: Set Matrix Zeroes
* Grind 75 - Medium
* @Topics: Array, Hash Table, Matrix
* @Time: O(M * N) @Space: O(1)
* Where M & N are the sizes of matrix rows & columns respectively
* Question states: 'You must do it in place'
*/

void setZeroes(vector<vector<int>>& matrix) {
    const int m = matrix.size(), n = matrix[0].size();
    
    //Store booleans whether a zero is located at 1st row or 1st col.
    bool firstRow = false, firstCol = false;
    
    //Loop through matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //If curr. elem. is zero
            if (matrix[i][j] == 0) {
                //Make first elem. of row zero
                matrix[i][0] = 0;
                //And first elem. of col zero
                matrix[0][j] = 0;
                //If curr. row index is the 1st row, mark bool var.
                if (i == 0) {
                    firstRow = true;
                }
                //If curr. col. index is the 1st col., mark bool var.
                if (j == 0) {
                    firstCol = true;
                }
            }
        }
    }

    //Loop again, this time starting at 2nd row and 2nd col.   
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            //If the 1st elem. of row or 1st. elem. of col. is zero
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                //Mark curr. elem. as zero
                matrix[i][j] = 0;
            }
        }
    }
    
    //If there was a zero in the 1st row
    if (firstRow) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
    
    //There was a zero in the 1st col.
    if (firstCol) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}