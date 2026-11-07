class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        

        int result = INT_MAX;
        if(row == 1){
            return matrix[0][0];
        }

        
        for(int i = 1; i < row; i++){
            int prev1 = INT_MAX, prev2 = INT_MAX, indexOfMin = -1;

            for(int k = 0; k < col; k++){
                int val = matrix[i-1][k];
                if(val < prev1){
                    prev2 = prev1;
                    prev1 = val;
                    indexOfMin = k;
                }
                else if(val < prev2){
                    prev2 = val;
                }
            }
    
            for(int j = 0; j < col; j++){
               
                int prev = (indexOfMin == j) ? prev2 : prev1;

                matrix[i][j] += prev;


                if(i == row-1){
                    result = min(result, matrix[i][j]);
                }

            }
        }

        return result;
    }
};