/**
* Alfredo Renteria
* Leetcode Problem #515: Find Largest Value In Each Tree Row
* Mock OA - Medium
* @Topics: Tree, DFS, BFS, Binary Tree
* @Time: O(n) @Space: O(n)
* Where n are the # of nodes in the tree
*/

#include <algorithm>
#include <limits>
#include <iostream>
#include <queue>
#include <vector>

//Depth First Search
std::vector<int> largestValues(TreeNode* root) {
    //Initialize vector that will store the largest values from each row
    std::vector<int> lrgVals;
    //Call DFS on root, level 1 of the tree, and vector
    dfs(root, 1, lrgVals);
    return lrgVals;
}

void dfs(TreeNdoe* node, int level, std::vector<int>& lrgVals) {
    //If node is null, get out
    if (!node) {
        return;
    }
    //Occurs when we reach a new level
    if (lrgVals.size() < level) {
        lrgVals.push_back(std::numeric_limits<int>::min());
    }
    //The first time we reach a new level, comparison occurs with int min value
    //Subsequent checks, compare with largest value from level thus far
    if (node->val > lrgVals[level-1]) {
        lrgVals[level-1] = node->val;
    }
    //Recurse on left and right children; increase level
    dfs(node->left, level+1, lrgVals);
    dfs(node->right, level+1, lrgVals);
}

//Breadth First Search
std::vector<int> largestValues(TreeNode* root) {
    //No nodes in the tree, return empty vector
    if (!root) {
        return {};
    }    
    //Initialize vector that will store the largest values from each row
    std::vector<int> lrgVals;
   
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int N = q.size();
        //Initialize max element variable with int min value
        int maxE = std::numeric_limits<int>::min();
        while (N--) {
            TreeNode* node = q.front();
            //If there are left and right children, push them onto the queue
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
            //Update the largest value accordingly
            maxE = std::max(maxE, node->val);
            q.pop();
        }
        //Add large value to the vector
        lrgVals.push_back(maxE);
    }
    return lrgVals;
}