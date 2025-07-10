class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ab = 0;
        for(int num : nums){
            ab ^= num;
        }
        
        unsigned int diff = ab & (-(unsigned int)ab);

        int a = 0;
        int b = 0;
        for(int num : nums){
            if((num & diff) != 0){
                a ^= num;
            }else{
                b ^= num;
            }
        }

        return {a,b};
    }
};