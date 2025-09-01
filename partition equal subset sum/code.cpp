class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        sum /= 2;

        vector<bool> dp(sum+1, false);
        dp[0] = true;

        for(int num : nums){
            for(int i = sum; i >= num; i--){
                dp[i] = dp[i] || dp[i - num];
            }
        }


        return dp[sum];
    }
};