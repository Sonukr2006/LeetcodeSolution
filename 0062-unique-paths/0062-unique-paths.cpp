class Solution {
public:
    int helper(int i, int j, int n, int m, vector<vector<int>> &dp){
        // base case
        if(i == n-1 && j == m-1){
            return 1;
        }

        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        // only move down

        return dp[i][j] = helper( i, j+1, n, m, dp) + helper( i+1, j, n, m, dp);;
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int> (n, 1));
        for(int i = 0; i<m; i++){
            if(i == 0) continue;
            for(int j = 0; j < n; j++){
                if(j == 0) continue;

                int curr = 0;
                if(i-1 >= 0){
                    curr += dp[i-1][j];
                }
                if(j-1 >= 0){
                    curr += dp[i][j-1];
                }

                dp[i][j] = curr;
            }
        }
    
        return dp[m-1][n-1];
    }
};