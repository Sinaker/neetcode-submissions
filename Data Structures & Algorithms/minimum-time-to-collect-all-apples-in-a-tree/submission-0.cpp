class Solution {
   public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // Idk how I got this method
        // but I thought we should do a bottom up traversal (leaf to root)
        // assign cost if apple in node; cost = 1;
        // costNode = 2*(leftChildCost + rightChildCost) + (apple?)
        // 2 cuz cost to go then come back up

        // return
        unordered_map<int, vector<int>> adjList;
        for (auto e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        return dfs(0, adjList, hasApple, visited); // 0 is assumed to be root
    }
    int dfs(int node, unordered_map<int, vector<int>>& adjList, vector<bool>& hasApple,
            vector<bool>& visited) {
                visited[node] = true; // mark as visited

                int cost = 0;
                for(int e : adjList[node]) {
                    if(visited[e]) continue;
                    int childCost = dfs(e, adjList, hasApple, visited);

                    if (childCost > 0 || hasApple[e]) {
                        cost += childCost + 2;
                    }
                }
                
                return cost; 
            }
};