class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = INT_MIN;

        int currPro = 1;
        for(int i = 0; i < nums.size(); i++){
            currPro= currPro * nums[i];
            maxPro = max(maxPro, currPro);

            if(currPro == 0)
                currPro = 1;
        }
        currPro = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            currPro *= nums[i];
            maxPro = max(maxPro, currPro);

            if(currPro == 0)
                currPro = 1;
        }

        return maxPro;
    }
};