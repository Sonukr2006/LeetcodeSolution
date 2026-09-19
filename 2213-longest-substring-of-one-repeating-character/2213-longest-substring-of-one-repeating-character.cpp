struct Node{
    int length;
    int maxLength;
    char leftChar;
    char rightChar;
    int pre;
    int suff;
    Node(int l, int ml, char lc, char rc, int p, int s)
       : length(l), maxLength(ml), leftChar(lc), rightChar(rc), pre(p), suff(s) {}  
};
class ST{
    public:
    vector<Node> seg;

    ST(int n){
        Node node(0, 0, ' ', ' ', 0, 0);
        seg.resize(4 * n, node);
    }
    Node merge(Node L, Node R){
        Node node(0, 0, ' ', ' ', 0, 0);

        node.leftChar = L.leftChar;
        node.rightChar = R.rightChar;

        node.pre = L.pre;
        if(L.pre == L.length && L.rightChar == R.leftChar)
            node.pre = L.pre + R.pre;

        node.suff = R.suff;
        if(R.suff == R.length && L.rightChar == R.leftChar)
            node.suff = R.suff + L.suff;
        
        node.maxLength = max(L.maxLength, R.maxLength);
        if(L.rightChar == R.leftChar)
            node.maxLength = max(node.maxLength, L.suff+R.pre);
        
        node.length = L.length+R.length;

        return node;
    }
    void build(int ind, int low, int high, string &s){
        if(low == high){
            Node node(1, 1, s[low], s[high], 1, 1);
            seg[ind] = node;
            return;
        }

        int mid = low + ((high - low) >> 1);
        int left = (ind << 1) | 1;
        int right = (ind+1) << 1;

        build(left, low, mid, s);
        build(right, mid+1, high, s);

        seg[ind] = merge(seg[left], seg[right]);
    }

    void update(int ind, int low, int high, int i, char ch){
        if(low == high){
            seg[ind].leftChar = ch;
            seg[ind].rightChar = ch;

            return;
        }
        int mid = low + ((high - low) >> 1);
        int left = (ind << 1 ) | 1;
        int right = (ind+1) << 1;

        if(i <= mid)
            update(left, low, mid, i, ch);
        else
            update(right, mid+1, high, i, ch);
        
        seg[ind] = merge(seg[left], seg[right]);
    }

    int query(int ind, int low, int high, int L, int R){
        if(low > R || high < L)
            return 0;
        
        if(low >= L && high <= R){
            return seg[ind].maxLength;
        }

        int mid = low + ((high - low) >> 1);
        int left = (ind << 1) | 1;
        int right = (ind+1) << 1;

        int leftMax = query(left, low, mid, L, R);
        int rightMax = query(right, mid+1, high, L, R);

        return max(leftMax, rightMax);
    }
};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        vector<int> res;
        int n = s.size();

        ST sg(n);
        sg.build(0, 0, n-1, s);

        for(int i = 0; i < queryIndices.size(); ++i){
            char ch = queryCharacters[i];
            int ind = queryIndices[i];

            sg.update(0, 0, n-1, ind, ch);

            int len = sg.query(0, 0, n-1, 0, n-1);

            res.emplace_back(len);
        }

        return res;
    }
};