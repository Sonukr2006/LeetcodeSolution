class SegmentTree {
    public:
    vector<int> seg;
    SegmentTree(int n){
        
        seg.resize(4*n, 0);
    }
    void update(int idx, int low, int high, int i, int val){
        if(low == high){
            seg[idx] = val;
            return;
        }

        int mid = low+(high - low)/2;
        int left = idx << 1 | 1;
        int right = (idx + 1) << 1;

        if(i <= mid)
            update(left, low, mid, i, val);
        else
            update(right, mid+1, high, i, val);

        seg[idx] = max(seg[left], seg[right]);
    }
    int query(int idx, int low, int high, int l, int r){
        if(low > r || high < l) return 0;

        if(low >= l && high <= r) return seg[idx];

        int mid = low+(high - low)/2;
        int left = idx << 1 | 1;
        int right = (idx + 1) << 1;

        int leftVal = query(left, low, mid, l, r);
        int rightVal = query(right, mid+1, high, l, r);

        return max(leftVal, rightVal);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> res;
        set<int> st;
        st.insert(0);
        int n = 50000;
        SegmentTree sg(n);
        for(auto q : queries){
            if(q[0] == 1){
                int x = q[1];

                auto it = st.upper_bound(x);
                int next = (it != st.end()) ? *it : 0;
                int pre = *prev(it);

                sg.update(0, 0, n-1, x, x-pre);
                sg.update(0, 0, n-1, next, next-x);
                st.insert(x);
            }
            else{
                int x = q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                int pre = *prev(it);
                

                int maxGap = sg.query(0, 0, n-1, 0, pre);
                int best = max(maxGap, x-pre);

                res.push_back(best >= sz);
            }

        }
        return res;
    }
};