/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        // eh it's just bfs
        queue<Node*> q;

        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            Node dummy(69);
            Node* prevNode = &dummy;

            for(int i = 0; i<size; i++) {
                Node* currNode = q.front(); q.pop();

                prevNode->next = currNode;
                prevNode = currNode;

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            prevNode->next = nullptr;
        }
        return root;
    }
};