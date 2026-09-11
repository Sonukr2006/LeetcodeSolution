class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<bool> vis(n, false);

        for(int i = 0; i < fruits.size(); ++i){
            for(int j = 0; j<n; ++j){
                if(!vis[j]){
                    if(fruits[i] <= baskets[j]){
                        vis[j] = true;
                        break;
                    }
                }
            }
        }
        int res = 0;
        for(bool it : vis){
            if(!it){
                res++;
            }
        }
        return res;
    }
};