class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        for(int pile : piles){
            pq.push(pile);
        }

        for(int i  =0; i < k; i++){
            int n = pq.top();
            pq.pop();
            pq.push((n+1)/2);
        }

        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};