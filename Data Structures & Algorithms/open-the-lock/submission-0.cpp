class Solution {
public:
    int openLock(vector<string>& d, string target) {
        // Consider each node, with edge transforming by one step
        // BFS finds shortest path

        unordered_set<string> deadends(d.begin(), d.end());
        queue<pair<int, string>> q;
        unordered_set<string> visited;


        q.push({0,"0000"});

        while(!q.empty()) {
            auto [parCost, par] = q.front(); q.pop();
            if(deadends.count(par) || visited.count(par)) continue;

            if(par==target) return parCost; // bfs guaranteed to find lowest

            visited.insert(par);
            // Increment each dial
            for(int i = 0; i<4; i++) {
                string nei = par;
                nei[i] = (nei[i] == '9') ? '0' : nei[i] + 1;

                if(visited.count(nei)) continue;

                q.push({parCost+1, nei});
            }

        }
        return -1;
    }
};