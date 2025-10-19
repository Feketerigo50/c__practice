class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue;

            int slow = i;
            int fast = i;
            bool isForward = nums[i] > 0;
            while(true){
                slow = next_step(slow, nums[slow], n);
                if (nums[slow] == 0 || (nums[slow] > 0 != isForward))
                    break;

                fast = next_step(fast, nums[fast], n);
                if (nums[fast] == 0 || (nums[fast] > 0 != isForward))
                    break;

                fast = next_step(fast, nums[fast], n);
                if (nums[fast] == 0 || (nums[fast] > 0 != isForward))
                    break;

                if(slow == fast){
                    if(slow == next_step(slow, nums[slow], n)) break;
                    return true;
                }
            }
            
            slow = i;
            while((nums[slow] > 0) == flag && nums[slow] != 0){
                int tmp = next_step(slow, nums[slow], n);
                nums[slow] = 0;
                slow = tmp;
            }

        }

        return false;
    }

private:
    int next_step(int cur_step, int move, int size){
        return ((cur_step + move) % size + size) % size;
    }
};