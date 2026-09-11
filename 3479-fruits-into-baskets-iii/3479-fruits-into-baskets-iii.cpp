class SegmentTree {
    vector<int> seg;
public:
    SegmentTree(int n) {
        seg.assign(4 * n + 5, INT_MAX);
    }

    // build called as: build(arr, 0, 0, n-1)
    void build(const vector<int>& arr, int ind, int low, int high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = low + ((high - low) >> 1);
        int left = (ind << 1) | 1;    // 2*ind + 1
        int right = (ind + 1) << 1;   // 2*ind + 2

        build(arr, left, low, mid);
        build(arr, right, mid + 1, high);

        seg[ind] = max(seg[left], seg[right]);
    }

    // query called as: query(0, ql, qr, 0, n-1)
    bool query(int ind, int val, int low, int high) {
        // no overlap
        if(seg[ind] < val){
            return false;
        }

        // complete overlap
        if (low == high){
            seg[ind] = -1;
            return true;
        }

        // partial overlap
        int mid = low + ((high - low) >> 1);
        bool placed = false;

        if(seg[(ind << 1) | 1] >= val){
            placed = query((ind << 1) | 1,val, low, mid);
        }else{
            placed = query((ind + 1) << 1, val, mid + 1, high);
        }

        seg[ind] = max(seg[(ind << 1) | 1], seg[(ind + 1) << 1]);

        return placed;
    }

    // update called as: update(0, 0, n-1, idx, val)
    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + ((high - low) >> 1);
        int left = (ind << 1) | 1;
        int right = (ind + 1) << 1;

        if (i <= mid)
            update(left, low, mid, i, val);
        else
            update(right, mid + 1, high, i, val);

        seg[ind] = min(seg[left], seg[right]);
    }

    
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        SegmentTree sg(n);
        // void build(const vector<int>& arr, int ind, int low, int high) {

        sg.build(baskets, 0, 0, n-1);
        // bool query(int ind, int val, int low, int high) {
        
        int res =0;
        for(int i : fruits){
            if(sg.query(0, i, 0, n-1) == false){
                res++;
            }
        }
        return res;

    }
};