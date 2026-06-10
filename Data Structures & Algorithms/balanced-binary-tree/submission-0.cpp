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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        return abs(deepestLevel(root->left) - deepestLevel(root->right)) <=1;
    }
    int deepestLevel(TreeNode* curr) {
        if(curr==nullptr) return 0;

        queue<TreeNode*> q;
        int level = 0;

        q.push(curr);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i<size; i++) {
                TreeNode* curr = q.front(); q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
        }
        return level;
    }
};
