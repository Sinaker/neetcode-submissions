class DSU {
    public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n,1);

            for(int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if(parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        } // find parent, leader of pack
        bool unite(int a, int b) { // combines two graphs
            int x = find(a);
            int y = find(b);
            if(x==y) return false;

            if(size[x] < size[y]) swap(x,y); // assume x to be larger tree

            parent[y] = x; // 1-->2--->3 ; 4-->5 =======> parent[4] = 3
            size[x] += size[y];
            return true;
        } 
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int ans = n; // expect every node on its own

        for(auto& e: edges) {
            if(dsu.unite(e[0], e[1]))
                ans--; // We have successfully merged so subtract 
        }
        return ans;
    }
};
