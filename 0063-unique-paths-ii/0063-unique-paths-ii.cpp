class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<int>> &dp){
        // base case
        if(i == n-1 && j == m-1){
            return 1;
        }

        if(i >= n || j >= m) return 0;
        if(grid[i][j] == 1) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        
        // only move down

        return dp[i][j] = helper(grid, i, j+1, n, m, dp) + helper(grid, i+1, j, n, m, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(obstacleGrid, 0, 0, n, m, dp);
    }
};