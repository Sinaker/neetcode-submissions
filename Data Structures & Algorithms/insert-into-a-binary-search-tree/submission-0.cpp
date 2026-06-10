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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        
        TreeNode* curr = root;
        TreeNode* ancestor = nullptr;

        while(curr != nullptr) {
            ancestor = curr;
            if(curr->val < val) curr = curr->right;
            else if(curr->val > val) curr = curr->left;
        } 
        // Insert node
        if(val < ancestor->val) ancestor->left = new TreeNode(val);
        else ancestor->right = new TreeNode(val);

        return root;
    }
};