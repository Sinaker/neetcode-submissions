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
    TreeNode* prev = nullptr;
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
    bool inorder(TreeNode* curr) {
        if(curr == nullptr) return true; // Empty BST is a valid bst

        if(!inorder(curr->left)) return false;

        if(prev && prev->val >= curr->val) return false;
        prev = curr;

        if(!inorder(curr->right)) return false;
        return true;
    }
};
