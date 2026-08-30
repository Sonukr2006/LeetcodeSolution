class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_Heap;
        for(int i = 0; i < nums.size(); ++i){
            min_Heap.push(nums[i]);
            while(min_Heap.size() > k){
                min_Heap.pop();
            }
        }
        return min_Heap.top();
    }
};