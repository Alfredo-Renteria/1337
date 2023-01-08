/**
* Alfredo Renteria
* Leetcode Problem #872: Leaf-Similar Trees
* December LeetCoding Challenge - Easy
* @Topics: Tree, DFS, Binary Tree
* @Time: O(T1+T2) @Space: O(T1+T2)
* Where T1 & T2 are the lengths of the trees
*/

#include <iostream>
#include <queue>
#include <vector>

//Depth First Search helper function, where leaf values are added to vector
void leafValueSeq(TreeNode* root, std::vector<int>& valSequence) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        valSequence.push_back(root->val);
    }
    leafValueSeq(root->left, valSequence);
    leafValueSeq(root->right, valSequence);
};

//Returns true <--> the two given trees are leaf-similar
//Trees are considered leaf-similar if their leaf value sequence is the same
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    std::vector<int> leafVals1, leafVals2;

    leafValueSeq(root1, leafVals1);
    leafValueSeq(root2, leafVals2);

    return (leafVals1 == leafVals2);
}