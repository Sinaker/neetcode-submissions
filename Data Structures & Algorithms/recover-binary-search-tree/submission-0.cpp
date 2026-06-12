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

        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        for (int i = 1; i < res.size(); i++) {
            if (res[i-1]->val > res[i]->val) {
                if (!first)
                    first = res[i-1];

                second = res[i];
            }
        }

        swap(first->val, second->val);
    }
    void inOrder(TreeNode* curr, vector<TreeNode*>& res) {
        if(!curr) return ;

        if(curr->left) inOrder(curr->left, res);
        res.push_back(curr);
        if(curr->right) inOrder(curr->right, res);
    }
};