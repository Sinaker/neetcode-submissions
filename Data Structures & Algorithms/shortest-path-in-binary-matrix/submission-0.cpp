class Solution {
   public:
    const vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                                         {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[n-1][n-1]==1 || grid[0][0]==1) return -1;

        // shortest path is bfs until 1 and repeat until grid == n-1, n-1
        int ans = 0;

        // bfs
        queue<array<int, 3>> q;

        grid[0][0] = -1;  // visited
        q.push({1, 0, 0});

        while (!q.empty()) {
            auto [dist, i, j] = q.front(); q.pop();
            if(i==n-1 && j==n-1) return dist;
            for(auto [di, dj] : dirs) {
                int ni = i+di;
                int nj = j+dj;
                if(ni<0 || nj<0 || ni>=grid.size() || nj>=grid.size() || grid[ni][nj]!=0) continue;

                grid[ni][nj] = -1; // Mark visited
                q.push({dist+1, ni, nj});
            }
        }
        return -1;

    }
};