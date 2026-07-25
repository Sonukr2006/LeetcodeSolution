class Solution {
public:
    int maxProduct(int n) {
        int maxi = -1, maxiii  = -1;

        while(n != 0){
            int d = n % 10;

            if(d >= maxi){
                maxiii = maxi;
                maxi = d;
            }else if(d > maxiii) {
                maxiii = d;
            }
            n /= 10;
        }


        return maxi * maxiii;
    }
};