class Solution {
public:
    typedef pair<char, int> P;
    
    struct lamda{
        bool operator()(P &p1, P &p2){
            return p1.second < p2.second;
        }
    };
    string frequencySort(string s) {
        map<char, int> mp;

        for(char ch : s){
            mp[ch]++;
        }
        priority_queue<P, vector<P>, lamda> pq;

        for(const auto [key, val] : mp){
            pq.push({key, val});
        }

        string res = "";

        while(!pq.empty()){
            res.append(pq.top().second, pq.top().first);
            pq.pop();
        }

        return res;
    }
};