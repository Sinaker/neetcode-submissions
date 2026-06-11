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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        // One curr is null rest all nodes must be null
        bool nullSeen = false;

        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if(nullSeen && curr) return false; // If prev is null but curr is defined

            if(curr) {
                q.push(curr->left);
                q.push(curr->right);
            }
            else nullSeen = true;
            
        }
        return true;
    }
};