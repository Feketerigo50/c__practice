class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0; 
        }

        vector<int> dp(s.length()+1);
        dp[0] = 1;
        dp[1] = 1;
        int tmp;

        for(int i = 2; i < s.length()+1; i++){
            if(s[i-1] != '0'){
                dp[i] = dp[i-1];
            }

            tmp = (int)(s[i-2] - '0')*10 + (int)(s[i-1] - '0');
            if(tmp < 27 && tmp > 9){
                dp[i] += dp[i-2] ;
            }
        }

        return dp[s.length()];
    }
};