class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        if(n == 1) return 0;

        int sum = 0;
        int max_sum = Integer.MIN_VALUE;
        int tsum = 0;
        for(int i = 0; i < n; i++){
            tsum += i*nums[i];
            sum += nums[i];
        }
        
        max_sum = Math.max(max_sum, tsum);
        for(int i = 1; i < n; i++){
            tsum += sum - n*nums[n-i];
            max_sum = Math.max(max_sum, tsum);
        }

        return max_sum;
    }
}