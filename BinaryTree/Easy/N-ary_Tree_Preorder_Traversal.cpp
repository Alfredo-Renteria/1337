/**
* Alfredo Renteria
* Leetcode Problem #589: N-ary Tree Preorder Traversal
* Leetcode 75 Level 1 - Easy
* @Topics: Stack, Tree, DFS
* @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
*/

#include <iostream>
#include <vector>

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

void dfs(Node* node, std::vector<int>& vals) {
    if (!node) {
        return;
    }
    
    vals.push_back(node->val);
    
    const int n = node->children.size();
    
    for (int i = 0; i < n; i++) {
        dfs(node->children[i], vals);
    }
}

std::vector<int> preorder(Node* root) {
    std::vector<int> preOrderVals;
    
    dfs(root, preOrderVals);
    
    return preOrderVals;
}