class Solution {
public:
    int helper(vector<vector<int>>& m, int i, int j, int row, int col, vector<vector<int>> &dp){
        if(i >= row || j < 0 || j >= col) return INT_MAX;
        if(i== row-1) return m[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];

        int down = helper(m, i+1, j, row, col, dp);
        if(down != INT_MAX) down +=  m[i][j];

        int diagonalLeft = helper(m, i+1, j-1, row, col, dp);
        if(diagonalLeft != INT_MAX) diagonalLeft +=  m[i][j];

        int diagonalRight = helper(m, i+1, j+1, row, col, dp);
        if(diagonalRight != INT_MAX) diagonalRight +=  m[i][j];
        

        return dp[i][j] = min(down, min(diagonalLeft, diagonalRight));
    }
    //  mini = min(mini, helper(matrix, 0, i, row, col, dp));
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        

        int result = INT_MAX;
        if(row == 1){
            return matrix[0][0];
        }


        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){

                int down = INT_MAX;
                if(i-1 >= 0) down = matrix[i-1][j];

                int diagonalRight = INT_MAX;
                if(j+1 < col && i-1 >= 0) diagonalRight =  matrix[i-1][j+1];

                int diagonalLeft = INT_MAX;
                if(i-1 >= 0 && j-1 >= 0) diagonalLeft =  matrix[i-1][j-1];

                int mini = min({down, diagonalLeft, diagonalRight});

                matrix[i][j] += mini;

                if(i == row-1){
                    result = min(result, matrix[i][j]);
                }
            }
        }

        return result;
    }
};