/**
* Alfredo Renteria
* Leetcode Problem #1339: Maximum Product Of Splitted Binary Tree
* December '22 LeetCoding Challenge - Medium
* @Topics: Tree, DFS, Binary Tree
* @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
* Time: b/c in the worst case the trees can be skewed.
*/

#include <algorithm>
#include <iostream>

using LL = long long;

int maxProduct(TreeNode* root) {
    //For returning 'modulo' 10^9 + 7
    constexpr int m = 1e9+7;
    //Long long for storing total sum of all node values, and result
    LL totalSum = 0, res = 0;
    //The first run gets total sum
    totalSum = dfs(root, totalSum, res);
    //Second time to get result; 'max product of the sums of the 2 sub-trees'
    dfs(root, totalSum, res);
    return res % m;
}

int dfs(TreeNode* node, const LL totalSum, LL& res) {
    if (!node) {
        return 0;
    }
    //Get the current sum from node by recusring on left child, then right
    //And finally adding that node's value to the sum
    int currSum = dfs(node->left, totalSum, res);
    currSum += dfs(node->right, totalSum, res) + node->val;
    //The potential 'max product of the sums of 2 sub-trees' is calculated by:
    //Multiplying the current sum w/ the difference b/n total sum & current sum
    //Result is updated if this new calculation is > the registered result
    res = std::max(res, currSum * (totalSum-currSum));
    //Return current sum from node that called function
    return currSum;
} 