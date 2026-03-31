class Solution {
public:
    map<string, priority_queue<string, vector<string>, greater<string>>> adjList;
    vector<string> path;

    void dfs(string currNode) {
        while (!adjList[currNode].empty()) {
            string nextNode = adjList[currNode].top();
            adjList[currNode].pop(); // remove edge
            dfs(nextNode);
        }
        path.push_back(currNode); // post-order
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build graph
        for (auto& ticket : tickets) {
            adjList[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(path.begin(), path.end());
        return path;
    }
};