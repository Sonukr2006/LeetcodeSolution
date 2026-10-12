class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> mp;
        for(auto road : roads){  // O(n)
            mp[road[0]]++;
            mp[road[1]]++;
        }

        priority_queue<pair<int, int>> pq; // maximum
        // freq and cities
        for(auto m : mp){
            pq.push({m.second, m.first}); // m log(n) m = no. of cities 
        }

        map<int, int> temp;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            temp[p.second] = n--;  // O(m) m no. of cities
        }
        long long sum = 0;

        for(auto road : roads){
            sum += temp[road[0]] + temp[road[1]];
        }

        return sum;

    }
};