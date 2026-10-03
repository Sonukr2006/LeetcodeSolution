class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int stone : stones){
            pq.push(stone);
        }
        if(pq.size() == 1) return pq.top();

        while(pq.size() != 1){
            int firstVal = pq.top();
            pq.pop();
            int secVal = pq.top();
            pq.pop();

            if(firstVal != secVal){
                pq.push(firstVal - secVal);
            }else
                pq.push(0);
        }

        return pq.top();
    }
};