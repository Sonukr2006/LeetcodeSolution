class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int sizeQuality = quality.size();
        // calculate ratio = cost / quality;
        vector<pair<double, int>> worker_ratio(sizeQuality);
        for(int worker = 0; worker < sizeQuality; worker++){
            worker_ratio[worker] = make_pair((double)wage[worker]/quality[worker], quality[worker]);
        }
        // sort : why- because hum jab bhi har baar ratio nikalte hai jiska bhi ratio curr ratio se kam rhta hai uhi choose ho pata hai that why we want smaller ratio every curr worker ratio
        sort(worker_ratio.begin(), worker_ratio.end());

        priority_queue<double> pq;
        double sum = 0;
        double result = DBL_MAX;
        // because hame k-1 se start krna hai aur har baar is sum me ratio se multiply krenge then result me store krenge agr result se min huya to
        for(int i = 0; i < k-1; i++){
            pq.push((double)worker_ratio[i].second);
            sum += (double)worker_ratio[i].second;
        }

        for(int manager = k-1; manager < sizeQuality;manager++){
            double manager_ratio = worker_ratio[manager].first;
            sum += worker_ratio[manager].second;
            pq.push(worker_ratio[manager].second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            double currSum = manager_ratio * sum;
            if(currSum < result)
                result = currSum;
        }

        return result;
    }
};