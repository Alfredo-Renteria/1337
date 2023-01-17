/**
* Alfredo Renteria
* Leetcode Problem #173: Binary Search Tree Iterator
* Leetcode 75 Level 2 - Medium
* @Topics: Stack, Tree, Design, Binary Search Tree, Binary Tree, Iterator
* @Time: O(n) @Space: O(n)
* Where n is the # of nodes in the tree
*/

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushLeftChildren(root);
    }
    
    int next() {
        TreeNode* prior = s.top();
        s.pop();

        if (prior->right) {
            pushLeftChildren(prior->right);
        }
        
        return prior->val;
    }
    
    bool hasNext() {
        return !s.empty();    
    }

private:
    void pushLeftChildren(TreeNode* root) {
        s.push(root);
        
        while (root->left) {
            root = root->left;
            s.push(root);
        }
    }
   
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */