/**
* Alfredo Renteria
* Leetcode Problem #938: Range Sum Of BST
* December '22 LeetCoding Challenge - Easy
* @Topics: Tree, DFS, BST, Binary Tree
* @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
* Space b/c we are performing DFS traversal, recursive solution requires 
* additional space to maintain the function call stack. The worst-case 
* occurs when the tree is of chain shape, and we will reach all the way 
* down to the leaf node.
*/

#include <iostream>

//Method 1
int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) {
        return 0;
    }
    int sum = 0;
    //Value is somehwere in [low {...}] 
    //-- recurse on left child & potentially add to sum
    if (low < root->val) {
        sum += rangeSumBST(root->left, low, high);
    }
    //Value is somewhere in [{...} high] -- recurse on right " " " " " 
    if (root->val < high) {
        sum += rangeSumBST(root->right, low, high);
    }
    //Node value is in the 'inclusive' range; [low, high] -- add to sum
    if (low <= root->val && root->val <= high) {
        sum += root->val;
    }
    return sum;
}

//Method 2
int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    depthHelper(root, sum, low, high);
    return sum;
}

void depthHelper(TreeNode* root, int& sum, int low, int high) {
    if (!root) {
        return;
    }
    if (low < root->val) {
        depthHelper(root->left, sum, low, high);
    }
    if (root->val < high) {
        depthHelper(root->right, sum, low, high);
    }
    if (low <= root->val && root->val <= high) {
        sum += root->val;
    }
}