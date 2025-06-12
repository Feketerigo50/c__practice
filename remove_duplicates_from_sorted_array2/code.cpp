class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1) return 1;

        int front = 1;
        int back = nums.size();
        int last_num = nums[0];
        bool flag = false;
        while(front < back){
            if(nums[front] == last_num){
                if(!flag){
                    flag = true;
                }else{
                    for(int i = front+1; i < back; i++){
                        nums[i-1] = nums[i];
                    }
                    front--;
                    back--;
                }
            }else{
                flag = false;
            }
            last_num = nums[front];
            front++;
        }

        // int slow = 2;
        // for (int fast = 2; fast < nums.size(); ++fast) {
        //     if (nums[fast] != nums[slow - 2]) {
        //         nums[slow] = nums[fast];
        //         ++slow;
        //     }
        // }

        return back;
    }
};