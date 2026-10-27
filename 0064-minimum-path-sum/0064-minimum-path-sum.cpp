class Solution {
public:
    int helper(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j, int n, int m){
        // base case
        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        // only move down
        if(i == n-1) return grid[i][j] + helper(grid,dp, i, j+1, n, m);
        else if(j == m-1) return grid[i][j] + helper(grid,dp, i+1, j, n, m);


        return dp[i][j]=grid[i][j] + min(helper(grid,dp, i, j+1, n, m), helper(grid,dp, i+1, j, n, m));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(grid,dp, 0, 0, n, m);
    }
};