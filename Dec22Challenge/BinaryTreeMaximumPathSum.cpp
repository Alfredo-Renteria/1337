/**
* Alfredo Renteria
* Leetcode Problem #124: Binary Tree Maximum Path Sum
* December '22 LeetCoding Challenge - Hard
* @Topics: Dynamic Programming, Tree, DFS, Binary Tree
* @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
*/

#include <algorithm>
#include <limits>
#include <iostream>

int maxPathSum(TreeNode* root) {
    //Initialize maximum path sum variable with minimum int value as flag
    int maxSum = std::numeric_limits<int>::min();
    dfs(root, maxSum);
    return maxSum;
}
//DFS - Postorder Traversal
int dfs(TreeNode* node, int& maxSum) {
    if (!node) {
        return 0;
    }
    //Add path sum from left subtree
    //If negative, count it as zero
    int left = std::max(dfs(node->left, maxSum), 0);
    //Same process for the right subtree
    int right = std::max(dfs(node->right, maxSum), 0);
    //Max path sum is updated with the largest value between
    //The additions of the left & right sums plus the current node's value
    //Or its previous registered value
    maxSum = std::max(maxSum, left + right + node->val);
    //For this given node; node that made the call, return 
    //The max sum from the left or right subtrees plus the current node's value
    return std::max(left, right) + node->val;
}  