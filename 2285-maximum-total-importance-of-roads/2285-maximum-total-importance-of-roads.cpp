class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // let N = no. of cities, r = no. of road size;
        vector<long long> deg(n, 0);
        for(auto road : roads){  // O(r)
            deg[road[0]]++;
            deg[road[1]]++;
        }
        sort(deg.begin(), deg.end());
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += deg[i] * (i+1); // O(R)
        }

        return sum;
        // (r + N) log N
    }
};