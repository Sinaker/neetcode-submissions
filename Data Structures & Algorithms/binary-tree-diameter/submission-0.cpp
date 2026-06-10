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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // depth of leftMost node
        return deepestNode(root->left) + deepestNode(root->right);
    }
    int deepestNode(TreeNode* curr) { 
        if(curr == nullptr) return 0;
        
        if(curr->left) return 1 + deepestNode(curr->left);
        if(curr->right) return 1 + deepestNode(curr->right);

        return 1;
    }
};
