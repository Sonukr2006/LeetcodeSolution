class Solution {
public: // O (n-k log k) + O(n log n) + O(n) == O (n log n) where n is no. of ele 
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int sizeQuality = quality.size();
        // calculate ratio = cost / quality;
        vector<pair<double, int>> worker_ratio(sizeQuality);  
        for(int worker = 0; worker < sizeQuality; worker++){   // O(n)
            worker_ratio[worker] = make_pair((double)wage[worker]/quality[worker], quality[worker]);
        }
        // sort : why- because hum jab bhi har baar ratio nikalte hai jiska bhi ratio curr ratio se kam rhta hai uhi choose ho pata hai that why we want smaller ratio every curr worker ratio
        sort(worker_ratio.begin(), worker_ratio.end());   // O(n log n)

        priority_queue<double> pq;
        double sum = 0;
        double result = DBL_MAX;
        // because hame k-1 se start krna hai aur har baar is sum me ratio se multiply krenge then result me store krenge agr result se min huya to
       

        for(const auto& [r, q] : worker_ratio){ // O (n-k log k);
            sum += q;
            pq.push(q);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k)
                result = min(result, r*sum);
        }

        return result;
    }
};