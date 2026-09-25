class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> direction = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        int step = 0;

        int n = rows*cols;
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        while(ans.size()  < n){
            if(dir == 0 || dir == 2)
                step++;

            for(int i = 0; i < step; i++){
                rStart += direction[dir][0];
                cStart += direction[dir][1];

                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    ans.push_back({rStart, cStart});
            }

            dir = (dir+1)%4;
        }
        return ans;
    }
};