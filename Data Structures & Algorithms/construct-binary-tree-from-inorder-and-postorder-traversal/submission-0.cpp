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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(postorder.back());
        auto InOrderIt = find(inorder.begin(), inorder.end(), root->val);
        int idx = InOrderIt - inorder.begin();
        auto PostOrderIt = postorder.begin() + idx;

        vector<int> leftInOrder(inorder.begin(), InOrderIt);
        vector<int> rightInOrder(InOrderIt+1, inorder.end());
        vector<int> leftPostOrder(postorder.begin(), PostOrderIt);
        vector<int> rightPostOrder(PostOrderIt, postorder.end()-1); // dont incld root

        root->left = buildTree(leftInOrder, leftPostOrder);
        root->right = buildTree(rightInOrder, rightPostOrder);

        return root;
    }
};