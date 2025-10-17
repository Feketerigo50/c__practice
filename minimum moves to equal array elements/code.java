class Solution {
    public int minMoves(int[] nums) {
        int min_value = Integer.MAX_VALUE;
        int array_sum = 0;
        for(int num : nums){
            array_sum += num;
            min_value = Math.min(min_value, num);
        }

        return array_sum - min_value*nums.length;
    }
}