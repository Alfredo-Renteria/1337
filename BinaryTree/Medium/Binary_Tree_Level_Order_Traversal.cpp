/**
* Alfredo Renteria
* Leetcode Problem #102: Binary Tree Level Order Traversal
* Grind 75, Leetcode 75 Level 1 - Medium
* @Topics: Tree, BFS, Binary Tree
* BFS: @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
*/

#include <iostream>
#include <queue>
#include <vector>

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

//Breadth First Search
std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
        return {};
    }
    
    std::queue<TreeNode*> Q;
    Q.push(root);
    
    std::vector<vector<int>> nodeVals;
    
    while (!Q.empty()) {
        int size = Q.size();
        
        std::vector<int> temp;
        
        while (size > 0) {
            TreeNode* node = Q.front();
            Q.pop();
            
            temp.push_back(node->val);
            
            if (node->left) {
                Q.push(node->left);
            }
        
            if (node->right) {
                Q.push(node->right);
            }
        
            size--;
        }
        
        nodeVals.push_back(temp);
    }

    return nodeVals;
}