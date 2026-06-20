class Solution {
   public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        // DSU wont work this is directed problem
        // what if I create a reachability for any pair of nodes
        vector<vector<int>> adjList(numCourses);
        for (auto preq : prerequisites) {
            adjList[preq[0]].push_back(preq[1]);
        }
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        for (int i = 0; i < numCourses; i++) reachable[i][i] = true;

        for (int i = 0; i < numCourses; i++) {
            vector<bool> visited(numCourses, false);
            dfs(i, i, adjList, reachable, visited);
        }
        
        vector<bool> ans;
        for(auto q : queries) {
            ans.push_back(reachable[q[0]][q[1]]);
        }
        return ans;
    }
    void dfs(int source, int node, vector<vector<int>>& adj, vector<vector<bool>>& reachable,
             vector<bool>& visited) {
        visited[node] = true;
        reachable[source][node] = true;

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(source, nei, adj, reachable, visited);
            }
        }
    }
};