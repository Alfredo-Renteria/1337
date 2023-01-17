/**
* Alfredo Renteria
* Leetcode Problem #543. Diameter Of Binary Tree
* Grind 75, Leetcode 75 Level 2 - Easy
* @Topics: Tree, DFS, Binary Tree
* @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
*/

#include <algorithm>
#include <iostream>

int dfs(TreeNode* node, int& diameter) {
    if (!node) { 
        return 0;
    }
    
    int leftDepth = depth(node->left, diameter);
    int rightDepth = depth(node->right, diameter);
    
    diameter = std::max(diameter, leftDepth + rightDepth);
    
    return std::max(leftDepth, rightDepth) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    
    depth(root, diameter);
    
    return diameter;
}