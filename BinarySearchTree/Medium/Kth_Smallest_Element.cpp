/**
* Alfredo Renteria
* Leetcode Problem #230: Kth Smallest Element In A BST
* Grind 75, Leetcode 75 Level 2 - Medium
* @Topics: Tree, DFS, Binary Search Tree, Binary Tree
* Recursive Inorder: @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
*/

#include <iostream>

//Recursive Inorder
//Helper
void inorder(TreeNode* node, vector<int>& vals) {
    if (!node) {
        return;
    }
    //Left side
    inorder(node->left, vals);
    //Root node
    vals.push_back(node->val);
    //right side
    inorder(node->right, vals);
}

//Main
int kthSmallest(TreeNode* root, int k) {
    vector<int> vals;
    
    inorder(root, vals);
    
    return vals[k-1];      
}