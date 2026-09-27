class Solution {
public:
    bool wouldVoilate(int x, unordered_map<int, int> &freq){
        for(auto& [val, cnt] : freq){
            int need = x - val;
            if(freq.count(need)){
                if(need != val || cnt >= 2) return true;
            }
            int other = val - x;
            if(freq.count(other)) return true;
        }

        return false;
    }
    int maxSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int l = 0, ans = 0;
        for(int r = 0; r < nums.size(); r++){
            int x = nums[r];
            while(wouldVoilate(x, freq)){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
                
            }
            freq[x]++;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};