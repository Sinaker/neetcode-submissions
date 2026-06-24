class DSU {
    public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0; i<n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        int x = find(a);
        int y = find(b);

        if(x==y) return false;

        if(size[x] < size[y]) swap(x, y); // Assume x is larger

        parent[y] = x;
        size[x] +=size[y];
        return true;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = n;
        DSU dsu(n);

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j]==1 && dsu.unite(i,j)) ans--;
            }
        }
        return ans;
    }
};