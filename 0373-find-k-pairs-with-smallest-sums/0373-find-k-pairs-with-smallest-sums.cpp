class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<array<int, 3>> pq; // Max_Heap

        for(int i = 0; i < nums1.size(); ++i){
            for(int j = 0; j < nums2.size(); j++){
                int sum = nums1[i] + nums2[j];
                
                if(pq.size() < k)
                    pq.push({sum, nums1[i], nums2[j]});  // jab tak pq.size() < k hia push krte rho
                else if(pq.top()[0] > sum){ 
                    // is point pe agr pq me koi value hai aur abhi ek different indexes se sum cal kiya hai aur value, sum se greater hai aur hume smaller chahiye to aur size bhi mantain krni hai to phle ek ko pop kr lo q qki pq.size >= k huya hoga tabhi is if condition me aaya hoga. pop ke baad nye sum ko uske index ke sath push kro
                    pq.pop();
                    pq.push({sum, nums1[i], nums2[j]});
                }
                else
                    break;  // maan lo array sorted hai aur mujhe smallest chahiye aur abhi is point pe mujhe greater ele mil gya to mujhe aage jane ki kya need hai ?.
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        
        return ans;
    }
};