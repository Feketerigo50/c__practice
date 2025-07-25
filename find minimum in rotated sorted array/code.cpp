class Solution {
public:
    int findMin(vector<int>& nums) {
        int front = 0;
        int back = nums.size()-1;
        int mid;
        while(front < back){
            mid = front + (back-front)/2;
            
            if(nums[mid] > nums[back]){
                front = mid + 1;
            }else{
                back = mid;
            }
        }

        return nums[front];
    }
};