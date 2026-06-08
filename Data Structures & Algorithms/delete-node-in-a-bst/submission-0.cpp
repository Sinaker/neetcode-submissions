class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Found node to delete

            // Case 1: Leaf node
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // Case 2: Only right child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 3: Only left child
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 4: Two children
            TreeNode* succ = root->right;
            while (succ->left)
                succ = succ->left;

            root->val = succ->val;

            root->right = deleteNode(root->right, succ->val);
        }

        return root;
    }
};