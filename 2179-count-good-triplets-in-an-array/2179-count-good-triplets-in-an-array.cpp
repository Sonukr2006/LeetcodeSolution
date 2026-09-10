class SegmentTree  {
    public:
    vector<long long> seg;

    SegmentTree(int n){
        seg.resize(4*n, 0);
    }

    void update(int ind, int low, int high, int i){
        if(low == high){
            seg[ind] = 1;
            return;
        }

        int mid = low+(high-low)/2;
        int left = (ind << 1 )| 1;
        int right = (ind + 1) << 1;

        if(i <= mid)
            update(left, low, mid, i);
        else
            update(right, mid+1, high, i);
        
        seg[ind] = seg[left] + seg[right];
    }
    long long query(int ind, int low, int high, int l, int r){
        if (high < l || low > r) return 0;

        if(low >= l && high <= r) return seg[ind];

        int mid = low+(high-low)/2;
        int left = (ind << 1) | 1;
        int right = (ind + 1) << 1;

        long long leftQue = query(left, low, mid, l, r);
        long long rightQue = query(right, mid+1, high, l, r);

        return leftQue + rightQue;
    }

};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;

        int n = nums1.size();
        for(int i = 0; i < n; ++i){
            mp[nums2[i]] = i;
        }
        long long res = 0;
        SegmentTree sg(n);

        sg.update(0, 0, n-1, mp[nums1[0]]);

        for(int i = 1; i < n; ++i){
            int idx = mp[nums1[i]];

            long long leftCommon = sg.query(0, 0, n-1, 0, idx);
            long long leftNotComman = i - leftCommon;

            long long afterInx = (n-1) - idx;
            long long rightComman = afterInx - leftNotComman;

            res += (leftCommon * rightComman);
            sg.update(0, 0, n-1, idx);
        }

        return res;
    }
};