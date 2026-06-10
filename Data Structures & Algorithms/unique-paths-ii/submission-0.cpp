class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (grid[m-1][n-1] == 1 || grid[0][0] == 1) return 0;

        bool obstacle = false;
        for(int i = m-1; i>=0; i--) {
            if(grid[i][n-1]==1)  // obstacle reached
                obstacle = true;

            grid[i][n-1] = obstacle ? 0 : 1;
        }

        obstacle = false;
        for(int j = n-1; j>=0; j--) {
            if(grid[m-1][j]==1)
                obstacle = true;
            
            grid[m-1][j] = obstacle ? 0 : 1;
        }

        for(int i = m-2; i>=0; i--) {
            for(int j = n-2; j>=0; j--) {
                if(grid[i][j]==1) {
                    grid[i][j] = 0;
                    continue;
                }
                grid[i][j] = (long long)grid[i+1][j] + grid[i][j+1];
            }
        }
        return grid[0][0];
    }
};