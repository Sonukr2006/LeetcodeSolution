class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; ++i){
            if(i == n-1){
                
                dp[i] = max(dp[i-1], nums[i]);
                break;
            }
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        vector<int> dp2(n);
        dp2[0] = nums[n-1];
        dp2[1] = max(nums[n-1], nums[n-2]);

        for(int i = 2; i < n; ++i){
            if(i == n-1){
                
                dp2[i] = max(dp2[i-1], nums[n-i-1]);
                break;
            }
            dp2[i] = max(nums[n-i-1]+dp2[i-2], dp2[i-1]);
        }

        return max(dp[n-1], dp2[n-1]);
    }
};