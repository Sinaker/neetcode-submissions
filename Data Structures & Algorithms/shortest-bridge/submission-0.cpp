class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        // We will find one island, then use bfs until we find the other island

        int n = grid.size();
        bool found = false;
        for(int i = 0; i < n && !found; i++) {
            for(int j = 0; j < n && !found; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, grid);
                    found = true;
                }
            }
        }


        queue<array<int,3>> q; // dist, x, y
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++)
                if(grid[i][j]==67) {
                    grid[i][j] = -1; //visited
                    q.push({0,i,j});
                }
        }
        // now one island will have 67
        
        const vector<pair<int, int>> directions = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
        while(!q.empty()) {
            auto [dist, i, j] = q.front(); q.pop();

            for(const auto& [di, dj]: directions) {
                int ni = i+di;
                int nj = j+dj;

                if(ni<0 || nj<0 || ni>=grid.size() || nj>=grid.size() || grid[ni][nj]==-1)
                    continue;

                if(grid[ni][nj] == 1)   // found second island
                    return dist;

                grid[ni][nj] = -1;
                q.push({dist+1, ni, nj});
            }
        }
                return -1;
    }
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size() || grid[i][j]!=1) return ;
        grid[i][j] = 67; // visited

        const vector<pair<int, int>> directions = {{1,0}, {-1, 0}, {0,1}, {0,-1}};

        for(const auto& [di, dj]: directions) {
            int ni = i+di;
            int nj = j+dj;

            if(ni<0 || nj<0 || ni>=grid.size() || nj>=grid.size() || grid[ni][nj]!=1) continue;
            dfs(ni, nj, grid);
        }


    }
};