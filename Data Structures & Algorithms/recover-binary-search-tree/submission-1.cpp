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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> res;
        inOrder(root, res);
        
        
        int l = 1;
        int r = res.size()-1;

        while(res[l-1]->val <= res[l]->val || res[r-1]->val <= res[r]->val) { // exits when l and point
            if(res[l-1]->val <= res[l]->val) l++;
            if(res[r-1]->val <= res[r]->val) r--;
        }
        // node are l-1 and r
        swap(res[l-1]->val, res[r]->val);
    }
    void inOrder(TreeNode* curr, vector<TreeNode*>& res) {
        if(!curr) return ;

        if(curr->left) inOrder(curr->left, res);
        res.push_back(curr);
        if(curr->right) inOrder(curr->right, res);
    }
};