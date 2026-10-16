class Solution {
public:
    struct Node{
        char ch;
        int ind;
    };
    struct cmp{
        bool operator()(Node a, Node b){
            if(a.ch != b.ch) return a.ch > b.ch;
            return a.ind < b.ind;
        }
    };
    string clearStars(string s) {
        priority_queue<Node, vector<Node>, cmp> pq;

        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '*'){
                if(!pq.empty()){
                    auto temp = pq.top();
                    s[temp.ind] = '*';
                    pq.pop();
                }
            }
            if(s[i] != '*')
                pq.push({s[i], i});
            
        }
        string res = "";
        for(char ch : s){
            if(ch != '*'){
                res += ch;
            }
        }

        return res;
    }
};