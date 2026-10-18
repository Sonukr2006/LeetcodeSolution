class Solution {
public:
    const int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>> pq;
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }
        int count  = 1;
        int sum = 0;
        while(count <= right){
            auto temp = pq.top();
            pq.pop();

            if(count >= left) sum = (sum + temp[0]) % (int)(1e9+7);

            int newSum = temp[0];
            int index = temp[1];

            if(index+1 < n){
                newSum =  newSum + nums[index+1];
                pq.push({newSum, index+1});
            }

            count++;
        }
        return sum;
    }
};