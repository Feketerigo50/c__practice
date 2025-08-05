class Solution {
public:
    int getMoneyAmount(int n) {
        if(n == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int len = 2; len <= n; len++){
            for(int start = 1; start + len - 1 <= n; start++){
                int end = start + len - 1;
                dp[start][end] = INT_MAX;
                for(int pivot = start; pivot < end; pivot++){
                    int cost = pivot + max(dp[start][pivot-1], dp[pivot+1][end]);
                    dp[start][end] = min(dp[start][end], cost);
                }
            }
        }

        return dp[1][n];
    }
};