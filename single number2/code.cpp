class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one_time = 0, two_time = 0;

        for(int num: nums){
            one_time = (one_time ^ num) & ~two_time;
            two_time = (two_time ^ num) & ~one_time;
        }

        return one_time;
    }
};