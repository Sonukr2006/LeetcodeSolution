class Solution {
public:
    int helper(vector<int> &nums, int i, int tar, int sum){
        if(i >= nums.size() && tar == sum) return 1;

        if(i >= nums.size()) return 0;

        int plus = helper(nums, i+1, tar, sum+nums[i]);
        int minus = helper(nums, i+1, tar, sum-nums[i]);

        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, 0, target, 0);
    }
};