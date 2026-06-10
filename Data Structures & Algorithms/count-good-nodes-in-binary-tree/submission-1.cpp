class Solution {
public:
    int count = 0;

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }

    void dfs(TreeNode* curr, int maxSoFar) {
        if (!curr) return;

        if (curr->val >= maxSoFar)
            count++;

        maxSoFar = max(maxSoFar, curr->val);

        if(curr->left) dfs(curr->left, maxSoFar);
        if(curr->right) dfs(curr->right, maxSoFar);
    }
};