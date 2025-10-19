class Solution {
    public boolean circularArrayLoop(int[] nums) {
        int n = nums.length;

        for(int i = 0; i < n; i++){
            int slow = i;
            int fast = i;
            boolean isFoward = nums[i] > 0;

            while(true){
                slow = next_step(slow, nums[slow], n);
                if(nums[slow] == 0 || (nums[slow] > 0) != isFoward) break;

                fast = next_step(fast, nums[fast], n);
                if(nums[fast] == 0 || (nums[fast] > 0) != isFoward) break;

                fast = next_step(fast, nums[fast], n);
                if(nums[fast] == 0 || (nums[fast] > 0) != isFoward) break;

                if(slow == fast){
                    if(slow == next_step(slow, nums[slow], n)) break;
                    return true;
                }
            }

            slow = i;
            while(nums[slow] != 0 && (nums[slow] > 0) != isFoward){
                int tmp = next_step(slow, nums[slow], n);
                nums[slow] = 0;
                slow = tmp;
            }
        }

        return false;
    }

    private int next_step(int cur, int move, int size){
        return ((cur + move) % size + size) % size;
    }
}