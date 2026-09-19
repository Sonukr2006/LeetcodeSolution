class ST{
    public:
    vector<int> seg;
    ST(int n){
        seg.resize(4 * n);
    }

    void build(int ind, int low, int high, vector<int> &arr){
        if(low == high){
            seg[ind] = low;
            return;
        }

        int mid = low + ((high - low) >> 1);
        int left = (ind << 1) |1;
        int right = (ind + 1) << 1;

        build(left, low, mid, arr);
        build(right, mid+1, high, arr);

        if(arr[seg[left]] < arr[seg[right]])
            seg[ind] = seg[right];
        else
            seg[ind] = seg[left];

    }

    int query(int ind, int low, int high, int L, int R, vector<int> &arr){
        // No Overlap
        if(high < L || low > R)
            return -1;

        // Complete overlap
        if(low >= L && high <= R){
            return seg[ind];
        }
        
        // Partial Overlap
        int mid = low + ((high - low) >> 1);
        int left = ind << 1 | 1;
        int right = (ind + 1) << 1;

        int leftIndex = query(left, low, mid, L, R, arr);
        int rightIndex = query(right, mid+1, high, L, R, arr);

        if(leftIndex == -1)
            return rightIndex;
        
        if(rightIndex == -1)
            return leftIndex;

        if(arr[leftIndex] < arr[rightIndex])
            return rightIndex;
        
        return leftIndex;
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n= heights.size();
        vector<int> res;

        ST sg(n);
        sg.build(0, 0, n-1, heights);

        for(const auto& q : queries){
            int start = q[0];
            int end = q[1];
            int maxIndex = max(start, end);
            int minIndex = min(start, end);

            if(start == end){
                res.push_back(start);
                continue;
            }
            else if(heights[maxIndex] > heights[minIndex]){
                res.emplace_back(maxIndex);
                continue;
            }
            
            int l = maxIndex + 1;
            int r = n-1;
            int result = INT_MAX;
            while(l <= r){
                int mid = l + ((r - l) >> 1) ;

                int ind = sg.query(0, 0, n-1, l, mid, heights);

                if(heights[ind] > max(heights[maxIndex], heights[minIndex])){
                    result = min(result, ind);
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            res.emplace_back(result != INT_MAX ? result : -1);
        }
        return res;
    }
};