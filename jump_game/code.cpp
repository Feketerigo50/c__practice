class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur_pos = 0;
        int cur_step_limit = -1;
        int next_step_limit = 0;

        while(cur_step_limit != next_step_limit && next_step_limit < nums.size()){
            cur_step_limit = next_step_limit;
            while(cur_pos <= cur_step_limit){
                next_step_limit = max(nums[cur_pos] + cur_pos, next_step_limit);
                cur_pos++;
            }
        }

        if(next_step_limit >= nums.size()-1) return true;
        return false;
    }
};