class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int front = 0;
        int back = nums.size() -1;
        int mid;
        
        while(front <= back){
            mid = (front + back)/2;
            if(target == nums[mid]){
                return true;
            }
            
            if(nums[front] < nums[mid]){
                if(nums[front] <= target && target < nums[mid]){
                    back = mid - 1;
                }else{
                    front = mid + 1;
                }
            }else if(nums[front] > nums[mid]){
                if(nums[mid] < target && nums[back] >= target){
                    front = mid + 1;
                }else{
                    back = mid - 1;
                }
            }else{
                front++;
            }

        }

        return false;
    }
};