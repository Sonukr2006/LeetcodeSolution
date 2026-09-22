class Solution {
public:
    int count(int n, int k){
        int cnt = 0;

        while(n != 0){
            if(n % 10 == k) cnt++;
            n /= 10;
        }
        return cnt;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;

        for(auto& num : nums){
            cnt += count(num, digit);
        }

        return cnt;
    }
};