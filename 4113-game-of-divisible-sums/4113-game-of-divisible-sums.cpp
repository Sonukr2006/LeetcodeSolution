class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        long long dp1 =0,dp2=0;
        for(int i = n-1; i>= 0; i--){
            long long sum1 = nums[i];
            long long best = (sum1 %3 == 0) ? (sum1-dp1) : (sum1+dp1);

            if(i+1 < n){
                long long sum2 = (long long)nums[i+1]+nums[i];
                long long val = (sum2 %3 == 0) ? sum2-dp2 : sum2+dp2;
                best = max(best, val);
            }
            dp2 = dp1;
            dp1 = best;
        }
        return dp1;        
    }
};