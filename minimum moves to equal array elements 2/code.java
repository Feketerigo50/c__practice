class Solution {
    public int minMoves2(int[] nums) {
        int n = nums.length;
        int medium = n/2;
        Arrays.sort(nums);
        int target = nums[medium];

        int result = 0;
        for(int num : nums){
            result += Math.abs(num - target);
        }

        return result;
    }
}