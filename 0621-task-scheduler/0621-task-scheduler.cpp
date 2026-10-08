class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> countTask(26);

        for(char ch : tasks){
            countTask[ch- 'A']++; // constraint me sirf upper letter hoga
        }

        int time = 0;
        priority_queue<int> pq;

        for(int i : countTask){
            if(i > 0)
                pq.push(i); // jo task nhii hai push q krna 
        }

        while(!pq.empty()){
            vector<int> temp; // jaise n task add kr denge tab tak task ko is temp me store rkhenge

            for(int i = 1; i <= n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int i : temp){
                if(i > 0)
                    pq.push(i);
            }

            if(pq.empty())
                time += temp.size();
            else
                time += n+1;
        }

        return time;
    }
};