class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int n, vector<int>&nums, int p){
        if(i >= n) return 0;
        if(dp[i][p+1] != -1) return dp[i][p+1];

        int take = 0;
        if(p == -1 || nums[i] > nums[p]){
            take = 1+solve(i+1, n, nums, i);
        }
        int skip = solve(i+1, n, nums, p);

        return dp[i][p+1] = max(take, skip);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(0, n, nums, -1);

    }
};