class Solution {
    private Random rand;
    private int[] nums;
    private int[] origin;

    public Solution(int[] nums) {
        this.nums = nums.clone();
        this.origin = nums.clone();
        rand = new Random();
    }
    
    public int[] reset() {
        nums = origin.clone();
        return nums;
    }
    
    public int[] shuffle() {
        for(int i = nums.length-1; i > 0; i--){
            int idx = rand.nextInt(i+1);
            int temp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = temp;
        }

        return nums;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */