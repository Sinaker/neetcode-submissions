class DSU {
    public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0; i<n; i++)
            parent[i] = i; // evert node is a parent of itself
    }

    int find(int x) {
        // Find parent of node x
        if(parent[x]==x) return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        int x = find(a);
        int y = find(b);

        if(x==y) return false; // merge unsuccessful (cycle)

        if(size[x] < size[y]) swap(x,y); // Assume x to be larger tree than y
        parent[y] = x;
        size[x] += size[y];

        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto const& e : edges) {
            if(!dsu.unite(e[0]-1, e[1]-1)) {
                // Cycle detected
                return {e[0], e[1]};
            }
        }
        return {};
    }
};
