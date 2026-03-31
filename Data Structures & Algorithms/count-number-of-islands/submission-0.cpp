class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int island = 0;
        const vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == '1') {
                    q.push({i,j});
                    grid[i][j] = '\0'; // Mark as visited
                    while(!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        for(auto [dx, dy] : dirs) {
                            int nx = x + dx;
                            int ny = y + dy;
                            if(0<=nx && 0<=ny && nx<m && ny < n && grid[nx][ny]=='1') {
                                q.push({nx, ny});
                                grid[nx][ny] = '\0';
                            }
                        }
                    }
                    island++;
                }
            }
        }
        return island;
        
    }
};
