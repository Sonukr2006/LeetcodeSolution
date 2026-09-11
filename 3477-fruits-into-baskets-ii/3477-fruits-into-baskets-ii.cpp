class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<bool> vis(n, false);

        for(int i = 0; i < fruits.size(); ++i){
            for(int j = 0; j<n; ++j){
                if(baskets[j] != -1){
                    if(fruits[i] <= baskets[j]){
                        baskets[j] = -1;
                        break;
                    }
                }
            }
        }
        int res = 0;
        for(int it : baskets){
            if(it != -1){
                res++;
            }
        }
        return res;
    }
};