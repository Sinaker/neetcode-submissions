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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        // use deque
        deque<TreeNode*> dq;
        dq.push_back(root);

        bool rev = false;
        vector<vector<int>> ans;
        while(!dq.empty()) {
            int size = dq.size();
            vector<int> level;

            for(int i = 0; i<size; i++) {
                TreeNode* curr;

                if(!rev) {
                    // Noraml
                    curr = dq.front(); dq.pop_front();
                    if(curr->left) dq.push_back(curr->left);
                    if(curr->right) dq.push_back(curr->right);
                } else {
                    // reverse
                    curr = dq.back(); dq.pop_back();
                    if(curr->right) dq.push_front(curr->right);
                    if(curr->left) dq.push_front(curr->left);
                }
                level.push_back(curr->val);
            }
            rev = !rev; // toggle each level
            ans.push_back(level);
        }
        return ans;
    }
};