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
            // Increment, Decrement each dial
            for(int i = 0; i<4; i++) {
                string nextNei = par;
                string prevNei = par;

                nextNei[i] = (nextNei[i] == '9') ? '0' : nextNei[i] + 1;
                prevNei[i] = (prevNei[i] == '0') ? '9' : prevNei[i] - 1;

                if(!visited.count(nextNei) && !deadends.count(nextNei))
                    q.push({parCost+1, nextNei});

                if(!visited.count(prevNei) && !deadends.count(prevNei))
                    q.push({parCost+1, prevNei});
            }

        }
        return -1;
    }
};