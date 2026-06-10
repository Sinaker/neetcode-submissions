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

        dfs(curr->left, maxSoFar);
        dfs(curr->right, maxSoFar);
    }
};