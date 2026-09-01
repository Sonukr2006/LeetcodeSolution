class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, int> mp;
        set<int> invalid;
        for(int i = 0; i < nums.size(); ++i){
            if(invalid.count(nums[i])) continue;
            if(!(mp.find(nums[i]) != mp.end()))
                mp[nums[i]] = i;
            else {
                int index = mp[nums[i]];
                if(index == i-1){
                    mp[nums[i]] = i;
                }else{
                    invalid.insert(nums[i]);
                    mp.erase(nums[i]);
                }
            }
        }
        return mp.size();
    }
};