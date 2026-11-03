class Solution {
public:
    bool cheakPalindrome(string s, int start, int end){
        int i = start, n = end;

        while(i < n){
            if(s[i] != s[n]) return false;
            i++;
            n--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        if(n == 2 && s[0] == s[1]) return s;

        string temp = "";
        for(int i = 0; i < n-1; ++i){
            for(int j = i; j < n; ++j){
                if(s[i] == s[j]){
                    if(cheakPalindrome(s, i, j)){
                        if((j-i+1) > temp.size()){
                            temp = s.substr(i, j-i+1);
                        }
                    }
                }
            }
        }
        return temp;
    }
};