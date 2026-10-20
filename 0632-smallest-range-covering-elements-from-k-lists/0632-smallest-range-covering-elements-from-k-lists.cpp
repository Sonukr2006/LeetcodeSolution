class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<array<int, 3>> maxPQ;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>> > minPQ;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 1; j++){
                maxPQ.push({nums[i][j], j, i});
                minPQ.push({nums[i][j], j, i});
            }
        }
        int diff =  INT_MAX;
        int a;
        int b;
        while(true){
            int aa = minPQ.top()[0];
            int ind = minPQ.top()[1];
            int list = minPQ.top()[2];
            minPQ.pop();
            int bb = maxPQ.top()[0];
            int d = bb - aa;
            if(d < diff){
                diff = d;
                a = aa;
                b = bb;
            }
            if(ind+1 >= nums[list].size()) break;
            minPQ.push({nums[list][ind+1], ind+1, list});
            maxPQ.push({nums[list][ind+1], ind+1, list});


        }
        return {a, b};
    }
};