class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // If start or end is blocked, no paths possible
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;

        // Use long long to prevent overflow during intermediate steps
        vector<vector<long long>> dp(m, vector<long long>(n));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // If current cell is an obstacle, it contributes 0 paths
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                } 
                // Base case: The destination cell is 1 path (itself)
                else if (i == m - 1 && j == n - 1) {
                    grid[i][j] = 1;
                } 
                else {
                    long long down = (i + 1 < m) ? grid[i+1][j] : 0;
                    long long right = (j + 1 < n) ? grid[i][j+1] : 0;
                    grid[i][j] = down + right;
                }
            }
        }

        return grid[0][0];
    }
};