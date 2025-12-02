class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int zeros[32] = {0};
        int ones[32] = {0};

        for(int num : nums){
            for(int i = 0; i < 32; i++){
                if((num >> i) & 1){
                    ones[i] += 1;
                }else{
                    zeros[i] += 1;
                }
            }
        }

        int hammingDist = 0;
        for(int i = 0; i < 32; i++){
            hammingDist += zeros[i] * ones[i];
        }

        return hammingDist;
    }
};