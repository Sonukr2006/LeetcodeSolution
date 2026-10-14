class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n  = arr.size();
        vector<pair<double, pair<int, int>>> temp;
        for(int i=0; i < n; i++){
            for(int  j = i+1; j < n; j++){
                pair<double, pair<int, int>> d;
                d.first = (double)arr[i]/arr[j];
                d.second.first = arr[i];
                d.second.second = arr[j];

                temp.push_back(d);
            }
        }

        sort(temp.begin(), temp.end());

        return {temp[k-1].second.first, temp[k-1].second.second};
    }
};