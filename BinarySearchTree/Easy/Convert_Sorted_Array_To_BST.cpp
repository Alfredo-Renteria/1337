/**
* Alfredo Renteria
* Leetcode Problem #108: Convert Sorted Array To Binary Search Tree
* Grind 75, Leetcode 75 Level 2 - Easy
* @Topics: Array, Divide and Conquer, Tree, Binary Search Tree, Binary Tree
* @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
*/

#include <iostream>
#include <vector>

TreeNode* helper(std::vector<int>& nums, int left, int right){
    //Left ptr. crosses right
    if (left > right){
        return nullptr;
    }

    //Middle of nums will be root node
    int mid = left + (right - left) / 2;
    TreeNode* temp = new TreeNode(nums[mid]);
    
    //Left section from middle will be left subtree
    temp->left = helper(nums, left, mid-1);
    
    //Right section from middle will be right subtree
    temp->right = helper(nums, mid+1 , right);
    
    return temp;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    return helper(nums, left, right);
}