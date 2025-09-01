class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int i = 0; i < nums.length; i++){
            sum += nums[i];
        }
        if((sum & 1) == 1) return false;

        sum /= 2;

        boolean[] dp = new boolean[sum+1];
        dp[0] = true;
        for(int num : nums){
            for(int i = sum; i >= num; i--){
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[sum];
    }
}