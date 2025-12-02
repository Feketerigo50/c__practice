class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1) return 9;

        long upper = pow(10, n) - 1;

        for(int left = upper; left > 0; left--){
            
            long palin = left;
            long tmp = left;
            while(tmp > 0){
                palin = palin*10 + (tmp % 10);
                tmp = tmp / 10;
            }

            for(long factor = upper; factor * factor >= palin; factor--){
                if(palin % factor == 0){
                    return palin % 1337;
                }
            }
        }

        return -1;
    }
};