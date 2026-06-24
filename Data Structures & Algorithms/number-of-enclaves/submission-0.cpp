class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // dfs from edges mark them as -1
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i<m; i++) {
            if(grid[i][0]==1) dfs(i, 0, grid);
            if(grid[i][n-1]==1) dfs(i, n-1, grid);
        }

        for(int j = 0; j<n; j++) {
            if(grid[0][j]==1) dfs(0,j,grid);
            if(grid[m-1][j]==1) dfs(m-1,j,grid);
        }

        int ans = 0;
        for(int i = 0; i<m; i++) 
            for(int j = 0; j<n; j++)
                if(grid[i][j]==1) ans++;

        return ans;
        
    }
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) return ;

        grid[i][j] = -1;

        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);

    }
};