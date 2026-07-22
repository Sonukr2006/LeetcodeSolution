class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int oneCount = count(s.begin(), s.end(), '1');

        vector<int> inActive;
        int i = 0;
        while(i < s.length()){
            if(s[i] == '0' && i < s.length()){
                int start = i;
                while(i < s.length() && s[i] == '0') i++;
                inActive.push_back(i - start);
            }else{
                i++;
            }
        }

        int maxblock = 0;
        for(int i = 1; i < inActive.size(); i++){
            maxblock = max(maxblock, inActive[i] + inActive[i-1]);
        }
        return maxblock + oneCount;


    }
};