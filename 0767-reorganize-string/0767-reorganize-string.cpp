class Solution {
public:
    string reorganizeString(string s) {
        vector<int> mp(26, 0);
        for(char ch : s){
            mp[ch-'a']++;

            if(mp[ch-'a'] > (s.size()+1)/2) return "";
        }
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < mp.size(); i++){
            if(mp[i] == 0) continue;
            pq.push({mp[i], i+'a'});
        }

        string ans = "";
        while(pq.size() > 1){
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            ans.push_back(p1.second); p1.first--;
            ans.push_back(p2.second); p2.first--;

            if(p1.first > 0)
                pq.push(p1);

            if(p2.first > 0)
                pq.push(p2);
        }
        if(!pq.empty())
            ans.push_back(pq.top().second);

        return ans;
    }
};