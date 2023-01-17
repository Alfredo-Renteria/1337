/**
* Alfredo Renteria
* Leetcode Problem #437: Path Sum III
* Leetcode 75 Level 2 - Medium
* @Topics: Tree, DFS, Binary Tree
* @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
*/

#include <iostream>
#include <vector>

void preOrder(TreeNode* node, int targetSum, std::vector<int>& vals, int& nPaths) {
    if (!node) {
        return;
    }
    
    //Node
    vals.push_back(node->val);
    //Left
    if (node->left) {
        preOrder(node->left, sum, vals, nPaths);
    }
    //Right
    if (node->right) {
        preOrder(node->right, sum, vals, nPaths);
    }

    long long sum = 0;
    //From this node get a sum of values from parent to root
    for (int i = vals.size() - 1; i >= 0; i--) {
        sum += vals[i];
        //There is a targetSum amongst the nodes in this range
        if (sum == targetSum) {
            nPaths++;
        }
    }
    
    //Remove this node value from vals
    vals.pop_back();
}
int pathSum(TreeNode* root, int targetSum) {
    //For storing node values
    std::vector<int> vals;
    //'# of paths where the sum of values along the path equals targetSum'
    int nPaths = 0;
    
    preOrder(root, targetSum, vals, nPaths);
    
    return nPaths;
}