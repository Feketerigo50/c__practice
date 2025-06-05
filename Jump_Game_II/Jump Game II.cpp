class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_endpoint = 0;
        int farest = 0;
        int jumps = 0;
        
        for(int i=0; i<nums.size()-1; i++){
            farest = max(farest, i + nums[i]);
            if(i == cur_endpoint){
                jumps += 1;
                cur_endpoint = farest;
            }
        }

        return jumps;
    }
};