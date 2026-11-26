class Solution {
public:
    typedef long long ll;
    int n;
        long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
        ll even = 0, odd = 0;

        for(int i = n-1; i >= 0; --i){
            ll curr_even =  max(even, (long long)nums[i] + odd);
            ll curr_odd =  max(odd, -(long long)nums[i] + even);

            even = curr_even;
            odd = curr_odd;
        }   
        return even;
    }
};