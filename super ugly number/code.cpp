class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n, 0);
        dp[0] = 1;

        int n_p = primes.size();
        vector<int> index(n_p, 0);
        vector<long> value(primes.begin(), primes.end());

        for(int i = 1; i < n; i++){
            long min_val = *min_element(value.begin(), value.end());
            dp[i] = min_val;

            for(int j = 0; j < value.size(); j++){
                if(value[j] == min_val){
                    index[j]++;
                    value[j] = (long)primes[j] * dp[index[j]];
                }
            }
        }

        return dp[n-1];
    }
};