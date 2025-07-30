class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int length = nums.size();
        if(length < 3) return false;

        vector<int> incre;
        incre.push_back(nums[0]);
        for(int i = 1; i < length; i++){
            int num = nums[i];
            auto it = lower_bound(incre.begin(), incre.end(), num);

            if(it == incre.end()){
                if(incre.size() < 3){
                    incre.push_back(num);
                }
            }else{
                *it = num;
            }
        }

        return incre.size() == 3;
    }
};