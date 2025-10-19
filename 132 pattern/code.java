class Solution {
    public boolean find132pattern(int[] nums) {
        Stack<Integer> stk = new Stack<>();
        int k = Integer.MIN_VALUE;

        for(int i = nums.length-1; i >= 0; i--){
            if(nums[i] < k) return true;

            while(!stk.isEmpty() && stk.peek() < nums[i]){
                k = stk.pop();
            }

            stk.push(nums[i]);
        }
        
        return false;
    }
}