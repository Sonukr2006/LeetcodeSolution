class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int spfSize = 100005;
        // Create vector of smallest prime factor
        vector<int> spf(100005);
        for(int i = 0; i<spfSize; ++i){
            spf[i] = i;
        }

        // find smallest prime factor of each number
        for(int i = 2; i * i <= spfSize; ++i){
            if(spf[i] == i){
                for(int j = i*i; j < spfSize; j += i){
                    if(spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }

        int maxLength = 0;
        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;
        while(j < nums.size()){
            
            int number = nums[j];
            while(number > 1){
                mp[spf[number]]++;
                number = number / spf[number];
            }
            
            while(mp.size() > k){
                int numToRemove = nums[i];
                while(numToRemove > 1){
                    mp[spf[numToRemove]]--;

                    if(mp[spf[numToRemove]] == 0){
                        mp.erase(spf[numToRemove]);
                    }
                    numToRemove = numToRemove / spf[numToRemove];
                }
                i++;
            }
            
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        return maxLength;

    }
};