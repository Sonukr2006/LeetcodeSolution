class Solution {
public:

    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        
        for(int i = n-2; i >= 0; i--){
            
            for(int j = 0; j < triangle[i].size(); j++){
                
                int left = triangle[i+1][j];
                int right = triangle[i+1][j+1];

                triangle[i][j] += min(left, right);
                
            }
        }
        return triangle[0][0];
    }
};