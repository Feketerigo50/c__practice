class Solution {
    public int totalHammingDistance(int[] nums) {

        int hammingDist = 0;
        for(int i = 0; i < 32; i++){
            int ones = 0;

            for(int num : nums){
                ones += (num >> i) & 1;
            }

            int zeros = nums.length - ones;

            hammingDist += zeros * ones;
        }

        return hammingDist;
    }
}