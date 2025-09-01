class Solution {
    public int dpSolution(int[] nums, int k){
        int n = nums.length;

        long[] prefix = new long[n+1];
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        long[][] dp = new long[n+1][k+1];
        for(int i = 0; i <= n; i++){
            Arrays.fill(dp[i], Long.MAX_VALUE);
        }
        dp[0][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int tmpk = 1; tmpk <= k; tmpk++){
                for(int j = 0; j < i; j++){
                    long sum = prefix[i] - prefix[j];
                    dp[i][tmpk] = Math.min(dp[i][tmpk], Math.max(dp[j][tmpk-1], sum));
                }
            }
        }

        return (int) dp[n][k];
    }

    boolean ifCanSplit(int[] nums, int k, long target_sum){
        long cur_sum = 0;
        long tmpk = 1;

        for(int num : nums){
            if(num + cur_sum > target_sum){
                cur_sum = num;
                tmpk++;
                if(tmpk > k) return false;
            }else{
                cur_sum += num;
            }
        }

        return true;
    }


    public int splitArray(int[] nums, int k) {
        // return dpSolution(nums, k);
        long left = 0, right = 0;
        for(int num : nums){
            left = Math.max(left, num);
            right += num;
        }

        long result = right;
        while(left <= right){
            long mid = left + (right - left)/2;
            if(ifCanSplit(nums, k, mid)){
                right = mid - 1;
                result = mid;
            }else{
                left = mid + 1;
            }
        }

        return (int) result;
    }
}