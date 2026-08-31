class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        vector<pair<int, int>> pq;

        for(int i = 0; i < nums.size(); ++i){
            mp[nums[i]]++;
        }


        for(const auto& [val, count] : mp ){
            pq.push_back({count, val});
        }

        sort(pq.rbegin(), pq.rend());
        for(int i = 0; i < k; ++i){
            ans.push_back(pq[i].second);
        }


        return ans;
    }
};