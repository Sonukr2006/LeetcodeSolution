class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
    int climbStairs(int n) {
        
        int prev2 = 1;
        int prev1 = 1;

        for(int i = 2; i <= n; i++){
            int curri = prev2 ;
            prev2 = prev2 + prev1;
            prev1 = curri;
        }

        return prev2;
    }
};