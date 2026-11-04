class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);
        for(int i = n-2; i >= 0; --i){
            if(nums[i] == 0) dp[i] = -1;
            else if(nums[i] >= n-i){
                dp[i] = 1;
            }
            else{
                int miniIndex = INT_MAX;
                for(int j = nums[i]; j > 0; --j){
                    if(i+j < n && dp[i+j] != -1)
                        miniIndex = min(miniIndex, dp[i+j]);
                }

                dp[i] = miniIndex != INT_MAX ? miniIndex+1 : -1; 
            }
        }

        return dp[0];
    }
};