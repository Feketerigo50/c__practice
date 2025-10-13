class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;

        int result = 0;
        vector<unordered_map<long long, long long>> dp(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                long long diff = (long long) nums[i] - nums[j];
                int count = 0;
                if(dp[j].contains(diff)){
                    count = dp[j][diff];
                }
                dp[i][diff] += count + 1;
                result += count;
            }
        }

        return result;
    }
};