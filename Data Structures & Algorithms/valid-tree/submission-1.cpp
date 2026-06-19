class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Tree must have exactly n-1 edges
        if (edges.size() != n - 1) return false;

        unordered_map<int, vector<int>> adjList;

        for (auto& e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        dfs(0, -1, adjList, visited);

        for (bool b : visited)
            if (!b) return false;

        return true;
    }

    void dfs(int node,
             int parent,
             unordered_map<int, vector<int>>& adjList,
             vector<bool>& visited) {

        visited[node] = true;

        for (int nei : adjList[node]) {
            if (nei == parent) continue;

            if (!visited[nei])
                dfs(nei, node, adjList, visited);
        }
    }
};