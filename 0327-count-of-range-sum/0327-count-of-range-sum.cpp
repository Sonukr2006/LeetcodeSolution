class Solution {
public:
    // void merge(vector<int> &arr, int low, int mid, int high){
    //     vector<int> temp;
    //     int left = low; int right = mid+1;

    //     while(left <= mid && right <= high){
    //         if(arr[left] <= arr[right]){
    //             temp.push_back(arr[left++]);
    //         }
    //         else{
    //             temp.push_back(arr[right++]);
    //         }
    //     }

    //     while(left <= mid)
    //         temp.push_back(arr[left++]);

    //     while(right <= high)
    //         temp.push_back(arr[right++]);

    //     for(int i = low; i <= high; ++i){
    //         arr[i] = temp[i-low];
    //     }

    // }
    void merge(vector<long long> &arr, int low, int mid, int high){
        vector<long long> temp;
        int left = low;
        int right = mid+1;

        while(left <= mid && right <= high){
            if(arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
            
        }

        while(left <= mid){
            temp.push_back(arr[left++]);
        }

        while(right <= high){
            temp.push_back(arr[right++]);
        }

        for(int i = low; i <= high; ++i){
            arr[i] = temp[i-low];
        }
    }
    int count(vector<long long>& arr, int low, int mid, int high, int lower, int upper) {
        int cnt = 0;
        
        // Right half mein window dhoondhne ke liye 2 pointers
        int start = mid + 1;
        int end = mid + 1;
        
        for (int i = low; i <= mid; ++i) {
            
            // Start pointer ko wahan tak le jao jahan difference lower limit ko cross kare
            while (start <= high && arr[start] - arr[i] < lower) {
                start++;
            }
            
            // End pointer ko wahan tak le jao jahan difference upper limit se bada ho jaye
            while (end <= high && arr[end] - arr[i] <= upper) {
                end++;
            }
            
            // Valid pairs honge in dono ke beech ke elements
            cnt += (end - start);
        }
    
        return cnt;
    }
    int mergeSort(vector<long long> & arr, int low, int high, int lower, int upper){
        if(low >= high) return 0;


        int mid = low + (high - low) / 2;
        int cnt = 0;
        cnt += mergeSort(arr, low, mid, lower, upper);
        cnt += mergeSort(arr, mid+1, high, lower, upper);
        cnt += count(arr, low, mid, high, lower, upper);
        merge(arr, low, mid, high);
        return cnt;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0); 
    
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i]; 
        }

        return mergeSort(pref, 0, n, lower, upper);
    }
};