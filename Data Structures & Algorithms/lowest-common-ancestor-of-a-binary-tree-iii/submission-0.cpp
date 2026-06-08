/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        // Since we have parent, we can just up traverse until convergence
        int levelP = 0;
        int levelQ = 0;

        Node* tempP = p;
        Node* tempQ = q;

        while(tempP->parent || tempQ->parent){
            if(tempP->parent) {
                tempP = tempP->parent;
                levelP++;
            }
            if(tempQ->parent) {
                tempQ = tempQ->parent;
                levelQ++;
            }
        }
        

        while(levelP != levelQ) {
            if(levelP>levelQ) {
                p = p->parent;
                levelP--;
            } else {
                q = q->parent;
                levelQ--;
            }
        }

        // Now since they are on same level
        while(p!=q) {
            p = p->parent;
            q = q->parent;
        }
        return p;
        
    }
};