/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node*
_bottomRight) { val = _val; isLeaf = _isLeaf; topLeft = _topLeft; topRight = _topRight; bottomLeft =
_bottomLeft; bottomRight = _bottomRight;
    }
};
*/

class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(grid, 0, n-1, 0, n-1);
    }
    Node* dfs(vector<vector<int>>& grid, int startX, int endX, int startY, int endY) {
        if(startX==endX && startY==endY)
            return new Node(grid[startX][startY] == 1, true);
        
        int midX = startX + (endX - startX) / 2;
        int midY = startY + (endY - startY) / 2;

        Node* tl = dfs(grid, startX, midX, startY, midY);
        Node* tr = dfs(grid, startX, midX, midY+1, endY);
        Node* bl = dfs(grid, midX+1, endX, startY, midY);
        Node* br = dfs(grid, midX+1, endX, midY+1, endY);

        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val == tr->val &&
            tr->val == bl->val && bl->val == br->val)
            return new Node(tr->val, true); // leaf node with val
        
        // else 
        Node* currNode = new Node(false, false);
        currNode->topLeft = tl;
        currNode->topRight = tr;
        currNode->bottomLeft = bl;
        currNode->bottomRight = br;
        return currNode;
    }
};