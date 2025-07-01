class Solution {
public:
    void reverse(vector<int>&nums, int front, int back){
        while(front < back){
            int tmp = nums[front];
            nums[front] = nums[back];
            nums[back] = tmp;
            front++;
            back--;
        }

        return;
    }

    void rotate(vector<int>& nums, int k) {
        int move = k % nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, move-1);
        reverse(nums, move, nums.size()-1);
        return;
    }
};