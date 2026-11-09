class Solution {
public:
    int helper(int i, int j1, int j2, int r, int c, vector<vector<int>> &g, vector<vector<vector<int>>> &dp){
        // edge case
        if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e8;

        // base base
        if(i == r-1){
            if(j1 == j2) return g[i][j1];

            return g[i][j1] + g[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int currentCherries = (j1 == j2) ? g[i][j1] : (g[i][j1] + g[i][j2]);

        // Try all 9 combinations of moves for both robots
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int nextCherries = helper(i + 1, j1 + dj1, j2 + dj2, r, c, g, dp);
                maxi = max(maxi, currentCherries + nextCherries);
            }
        }

        return dp[i][j1][j2] = maxi;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int> (c, -1)));
        return helper(0, 0, c-1, r, c, grid, dp);
    }
};