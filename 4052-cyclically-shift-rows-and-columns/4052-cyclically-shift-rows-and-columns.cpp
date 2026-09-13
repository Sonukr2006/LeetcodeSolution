class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        int m = grid[0].size();

        for(int i = 0; i < n; ++i){
            int k = rowShift[i] % n;

            vector<int> temp(n);
            for(int j = 0; j < n; ++j){
                temp[j] = grid[i][(j+k)%n];
            }

            grid[i] = temp;
        }

        for(int j = 0; j < n; ++j){
            int k = colShift[j] % n;

            vector<int> temp(n);
            for(int i = 0; i < n; ++i){
                temp[i] = grid[(i+k)%m][j];
            }
            for(int i = 0; i < n; i++){
                grid[i][j] = temp[i];
            }
        }

        return grid;
    }
};