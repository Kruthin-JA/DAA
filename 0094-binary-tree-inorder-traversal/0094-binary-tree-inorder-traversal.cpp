#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    void inorderTraversalHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        // Traverse left subtree
        inorderTraversalHelper(root->left, result);
        
        // Visit the root node
        result.push_back(root->val);
        
        // Traverse right subtree
        inorderTraversalHelper(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversalHelper(root, result);
        return result;
    }
};


