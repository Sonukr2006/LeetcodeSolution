class Solution {
public:
    struct Node{
        int p;
        int c;
    };
    struct cmp{
        bool operator()(Node a, Node b){
            return a.c > b.c; // c chhota upar
        }
    };
    struct cmpMaxP{
        bool operator()(Node a, Node b){
            return a.p < b.p; // p bada upar
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<Node, vector<Node>, cmp> pq;
        for(int  i = 0; i < profits.size(); i++){
            pq.push({profits[i], capital[i]});
        }
        priority_queue<Node, vector<Node>, cmpMaxP> temp;
        for(int i=0; i<k; i++){
            while(!pq.empty() && pq.top().c <= w){
                temp.push(pq.top());
                pq.pop();
            }
            if(temp.empty()) break;
            
            w += temp.top().p;
            temp.pop();
            

        }

        return w;

    }
};