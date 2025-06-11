class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_bound = 0;
        int cur_position = 0;
        int two_bound = nums.size()-1;

        while(cur_position <= two_bound){
            if(nums[cur_position] == 0){
                swap(nums[zero_bound++], nums[cur_position++]);
            }else if(nums[cur_position] == 1){
                cur_position++;
            }else{
                swap(nums[two_bound--], nums[cur_position]);
            }
        }

        return;
    }
};