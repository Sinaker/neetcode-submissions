/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // LCA means subtree leftsize
        if(root==nullptr) return nullptr;
        if(isIn(root->left, p) && isIn(root->left, q)) return lowestCommonAncestor(root->left, p, q);
        else if(isIn(root->right, p) && isIn(root->right, q)) return lowestCommonAncestor(root->right, p, q);

        return root;
    }
    bool isIn(TreeNode* root, TreeNode* p) {
        if(root == nullptr) return false;

        return isIn(root->left, p) || (root->val == p->val) || isIn(root->right, p);
    }
};