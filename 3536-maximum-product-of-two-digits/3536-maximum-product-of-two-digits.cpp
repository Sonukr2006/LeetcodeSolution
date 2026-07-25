class Solution {
public:
    int maxProduct(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int n = s.length();
        return (s[n-1] - '0') * (s[n-2] - '0');
    }
};