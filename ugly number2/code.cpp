class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int idx2 = 0;
        int idx3 = 0;
        int idx5 = 0;
        for(int i = 1; i < n; i++){
            int next2 = dp[idx2]*2;
            int next3 = dp[idx3]*3;
            int next5 = dp[idx5]*5;

            int next = min({next2, next3, next5});
            dp[i] = next;
            if(next == next2) idx2++;
            if(next == next3) idx3++;
            if(next == next5) idx5++;
        }

        return dp[n-1];
    }
};