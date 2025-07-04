class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = nums.size()+1;
        int front = 0;
        int back = 0;
        int tmp = 0;
        while(front != nums.size() && back != nums.size()){
            tmp += nums[back];
            if(tmp >= target){
                while(tmp >= target && front <= back){
                    tmp -= nums[front];
                    front++;
                }
                result = min(result, back - front + 2);
            }
            back++;
        }

        if(result == nums.size()+1) return 0;
        return result;
    }
};