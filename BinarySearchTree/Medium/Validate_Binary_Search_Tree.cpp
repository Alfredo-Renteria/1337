/**
* Alfredo Renteria
* Leetcode Problem #98: Validate Binary Search Tree
* Grind 75, Leetcode 75 Level 1 - Medium
* @Topics: Tree, DFS, Binary Search Tree, Binary Tree
* @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
*/

#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Recursive Traversal w/ Valid Range
bool validate(TreeNode* node, TreeNode* low, TreeNode* high) {
    if (!node) {
        return true;
    }

    if (low && node->val <= low->val || high && node->val >= high->val) {
        return false;
    }

    return validate(node->right, node, high) && validate(node->left, low, node);
}

bool isValidBST(TreeNode* root) {
    return validate(root, nullptr, nullptr);
}

