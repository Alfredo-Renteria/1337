/**
* Alfredo Renteria
* Leetcode Problem #1026: Maximum Difference Between Node And Ancestor
* December '22 LeetCoding Challenge - Medium
* @Topics: Tree, Depth First Search, Binary Tree
* @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the binary tree
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int helper(TreeNode* node, int curMax, int curMin) {
    //When node is null, calculate difference at that point
    if (!node) {
        return curMax - curMin;
    }
    //See if we have a new max & min
    curMax = std::max(curMax, node->val);
    curMin = std::min(curMin, node->val);
    //Recurse on left and right children
    int lhsDiff = helper(node->left, curMax, curMin);
    int rhsDiff = helper(node->right, curMax, curMin);
    //Return the greater difference between left hand side & right
    return std::max(lhsDiff, rhsDiff);
}

int maxAncestorDiff(TreeNode* root) {
    return helper(root, root->val, root->val);
}