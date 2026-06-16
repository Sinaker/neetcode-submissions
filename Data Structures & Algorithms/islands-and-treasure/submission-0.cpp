class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // mulitsource bfs
        queue<array<int, 3>> q;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++) 
                if(grid[i][j]==0) q.push({{i,j, 0}});

        const vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0, 1}, {0,-1}};

        while(!q.empty()) {
            auto [x, y, dist] = q.front(); q.pop();
            if(grid[x][y]==-1) continue;

            if(dist > grid[x][y]) continue;

            grid[x][y] = dist;

            for(const auto& [dx, dy]: directions) {
                int nx = x+dx;
                int ny = y+dy;
                if(nx<0 || nx>=m || ny<0 || ny>=n || dist+1 >grid[nx][ny]) continue;

                q.push({{nx, ny, dist+1}});
            }
        }
            
        
    }
};
