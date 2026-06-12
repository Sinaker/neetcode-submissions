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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // root, left, right
        // left, curr, right

        if(preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder.front());
        auto inOrderIt = find(inorder.begin(), inorder.end(), root->val);
        int idx = inOrderIt - inorder.begin();
        auto preOrderIt = preorder.begin() + idx;

        vector<int> leftInOrder(inorder.begin(), inOrderIt);
        vector<int> rightInOrder(inOrderIt+1, inorder.end());

        vector<int> leftPreOrder(preorder.begin() + 1, preOrderIt+1);
        vector<int> rightPreOrder(preOrderIt+1, preorder.end());

        root->left = buildTree(leftPreOrder, leftInOrder);
        root->right = buildTree(rightPreOrder, rightInOrder);
        return root;
    }
};
