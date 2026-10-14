struct Node{
    double frec;
    int i;
    int j;
    Node(double fre, int I, int J) : frec(fre), i(I), j(J) {}

    bool operator>(const Node& other) const {
        return frec > other.frec;
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n  = arr.size();
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        for(int i=0; i < n-1; i++){
            pq.emplace(1.0*arr[i]/arr[n-1], i, n-1);
        }

        for(int count=0; count < k-1; ++count){
            Node temp = pq.top();
            pq.pop();

            int i = temp.i;
            int j = temp.j - 1;

            if(j > i){
                pq.emplace((double)arr[i]/arr[j], i, j);
            }
        }

        Node r = pq.top();

        return {arr[r.i], arr[r.j]};
    }
};