class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second; // Ascending order
    }   
    string frequencySort(string s) {
        map<char, int> mp;

        for(char ch : s){
            mp[ch]++;
        }
        vector<pair<char, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp);

        string res = "";

        for(auto it : vec){
            int num = it.second;
            res.append(it.second, it.first);
        }

        return res;
    }
};