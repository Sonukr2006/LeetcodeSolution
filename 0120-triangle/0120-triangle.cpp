class Solution {
public:

    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        if(n == 1 && m == 1) return triangle[0][0];
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = n-1; i >= 0; i--){
            if(i == n-1){
                dp[n-1] = triangle[n-1];
                continue;
            }
            for(int j = 0; j < triangle[i].size(); j++){
                
                int left = triangle[i][j] + dp[i+1][j];
                int right = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(left, right);
                
            }
        }
        return dp[0][0];
    }
};