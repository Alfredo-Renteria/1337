/**
* Alfredo Renteria
* Leetcode Problem #297: Serialize and Deserialize Binary Tree
* Grind 75 - Hard
* @Topics: String, Tree, DFS, BFS, Design, Binary Tree
* @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
*/

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

//Encodes a tree to a single string
std::string serialize(TreeNode* root) {
    //Root is null, nothing to serialize -- return empty string
    if (!root) {
        return "";
    }
    //Init. queue and push root node
    std::queue<TreeNode*> q;
    q.push(root);
    //Init. string to hold serialization sequence
    std::string seq = "";
    //Loop until the queue is empty
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        //When node is null, add 'X' marker to sequence
        if (!node) {
            seq += "X,";
        } else {
            //Else convert node value to string and add to sequence
            seq += std::to_string(node->val) + ",";
            //Push this node's left and right nodes to queue
            q.push(node->left);
            q.push(node->right);
        }
    }
    return seq;
}

//Decodes your encoded data to tree
TreeNode* deserialize(std::string data) {
    //Data string is empty, nothing to decode -- return null pointer
    if (data.empty()) {
        return nullptr;
    }
    //Init. stream with data string as content inorder to decode tree
    std::stringstream decode(data);
    //Init. vector to hold decoded data
    std::vector<std::string> nodeVals;
    //Init. string to hold node element -- both int node vals & 'X'
    std::string seq = "";
    //Add every node element to the vector -- removing commas ','
    while (std::getline(decode, seq, ',')) {
        nodeVals.push_back(seq);
    }
    //Init. root node from vector
    TreeNode* root = new TreeNode(std::stoi(nodeVals[0]));
    //Init. queue and push root node
    std::queue<TreeNode*> q;
    q.push(root);
    //Init. index at 1, since root is already in queue
    int i = 1;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        //Left-side first
        //Get node element from vector and advance index
        seq = nodeVals[i++];
        //If node element is 'X' set node's left ptr. to null
        if (seq == "X") {
            node->left = nullptr;
        } else {
            //Else set node's left ptr to new Tree node element
            node->left = new TreeNode(std::stoi(seq));
            //Push this new node onto queue
            q.push(node->left);
        }
        //Now the right-side -- same process as left
        seq = nodeVals[i++];
        if (seq == "X") {
            node->right = nullptr;
        } else {
            node->right = new TreeNode(std::stoi(seq));
            q.push(node->right);
        }
    }
    return root;
}