class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        for(int i = 0; i < n; i++){
            tasks[i].emplace_back(i);
        }
        sort(tasks.begin(), tasks.end());

        long long curr_time = 0;
        int idx = 0;
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<int> result;

        while(idx < n || !pq.empty()){
            if(pq.empty() && curr_time < tasks[idx][0]){
                curr_time = tasks[idx][0];
            }

            while(idx < n && tasks[idx][0] <= curr_time){
                pq.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }

            pair<int, int> curr_task = pq.top();
            pq.pop();

            curr_time  += curr_task.first;

            result.push_back(curr_task.second);
        } 

        return result;
    }
};