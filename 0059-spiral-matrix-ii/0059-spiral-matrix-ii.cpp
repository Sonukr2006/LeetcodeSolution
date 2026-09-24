class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n));
        int cnt = 1;
        int left = 0;
        int top = 0;
        int right = matrix[0].size()-1;
        int bottom = n-1;
        while(left <= right && top <= bottom){
            for(int i = left; i <= right; i++){
                matrix[top][i] = cnt++;
            }
            top++;
            for(int i = top; i<= bottom; i++){
                matrix[i][right] = cnt++;
            }
            right--;
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    matrix[bottom][i] = cnt++;
                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    matrix[i][left] = cnt++;
                }
                left++;
            }
        }
        return matrix;
    }
};