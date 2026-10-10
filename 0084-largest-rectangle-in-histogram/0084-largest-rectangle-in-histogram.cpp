class Solution {
public:
    vector<int> nextSmallerFun(vector<int> &heights){
        stack<int> st;
        st.push(-1);
        vector<int> ans(heights.size());
        for(int i = heights.size()-1; i >= 0; i--){
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr) st.pop();
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    vector<int> preSmallerFun(vector<int> &heights){
        stack<int> st;
        st.push(-1);
        vector<int> ans(heights.size());
        for(int i = 0; i < heights.size(); i++){
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr) st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nextSmaller(n), preSmaller(n);

        nextSmaller = nextSmallerFun(heights);
        preSmaller = preSmallerFun(heights);
        int area = 0;
        for(int i = 0; i < n; i++){

            int height = heights[i];
            if(nextSmaller[i] == -1) nextSmaller[i] = n;

            int width = nextSmaller[i]  - preSmaller[i] - 1;

            int newArea = height * width;

            area = max(area, newArea);
        }

        return area;
    }
};