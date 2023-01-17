/**
* Alfredo Renteria
* Leetcode Problem #994: Rotting Oranges
* Grind 75, Leetcode 75 Level 2 - Medium
* @Topics: Array, BFS, Matrix
* BFS: @Time: O(m * n) @Space: O(m * n)
* Where m & n are the # of rows & columns respectively
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int orangesRotting(std::vector<std::vector<int>>& grid) {
    const int fourDirAdj[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    //Get # of rows & cols in the grid
    int m = grid.size(), n = grid[0].size();
    //Fresh oranges count & return var. for min. time lapse of no fresh oranges
    freshOranges = 0, minutes = 0;
    //Store indices; row & col, for rotten oranges
    std::queue<std::pair<int, int>> q;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                freshOranges++;
            } else if (grid[i][j] == 2) {
                q.push({i,j});
            }
        }
    }

    //Grid has no fresh oranges
    if (freshOranges == 0) {
        return 0;
    }
    
    while (!q.empty() && freshOranges > 0) {
        minutes++;
        int qSize = q.size();
        while (qSize > 0) {
            //Get row & col indices for rotten orange
            int r = q.front().first, c = q.front().second;
            q.pop();
            qSize--;

            //Check 4-directionally adjacent
            for (const auto& dir : fourDirAdj) {
                //Search row & col locations
                int sr = r + dir[0], sc = c + dir[1];
                //Search location is in bounds and fresh orange is found
                if (sr >= 0 && sr < m && sc >= 0 && sc < n && grid[sr][sc] == 1) {
                    //Decrease # of fresh oranges in the grid
                    freshOranges--;
                    //Mark it rotten
                    grid[sr][sc] = 2;
                    //Push rotten indices into queue
                    q.push({sr, sc});
                }
            }
        }
    }

    //Grid has fresh oranges unaffected by rotten oranges
    if (freshOranges != 0) {
        return -1;
    }
    
    return minutes;   
}