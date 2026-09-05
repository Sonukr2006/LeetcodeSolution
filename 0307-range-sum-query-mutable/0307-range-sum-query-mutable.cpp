
class NumArray {
public:
    vector<int> seg;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n > 0){
            seg.resize(4*n);
            buildSegmentTree(nums, seg, 0, 0, n-1);

        }
    }
    void buildSegmentTree(vector<int> &arr, vector<int> &seg, int ind, int low, int high){
        if(high == low){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low+high)/2;
        buildSegmentTree(arr, seg, ind << 1 | 1, low, mid);
        buildSegmentTree(arr, seg, (ind+1) << 1, mid+1, high);

        seg[ind] = seg[ind << 1 | 1] + seg[(ind+1) << 1];
    }
    void updateSegment(int ind, int index, int val, int low, int high, vector<int> &seg){
        if(high == low){
            seg[ind] = val;
            return;
        }

        int mid = (low+high)/2;
        if(index <= mid)
            updateSegment(ind << 1 | 1, index, val, low, mid, seg);
        else
            updateSegment((ind+1) << 1, index , val, mid+1, high, seg);

        seg[ind] = seg[ind << 1 | 1]+seg[(ind+1) << 1];
    }
    void update(int index, int val) {
        updateSegment(0, index, val, 0, n-1, seg);
    }
    
    int sumOfSegment(int ind, int low, int high, int l, int r){
        // no overlap
        
        if (r < low || l > high) {
            return 0;
        }

        // complete overlap
        if(l <= low && high <= r) return seg[ind];

        int mid = (low+high)/2;
        int left = sumOfSegment(ind << 1 | 1, low, mid, l, r);
        int right = sumOfSegment((ind+1) << 1, mid+1, high, l, r);

        return left+right;
    }
    int sumRange(int left, int right) {
        // no overlap
        if(n==0) return 0;
        return sumOfSegment(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */