class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int min_sofar = nums[0];
        int max_sofar = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int cur = nums[i];
            if(cur < 0){
                swap(min_sofar, max_sofar);
            }
            max_sofar = max(cur, max_sofar*cur);
            min_sofar = min(cur, min_sofar*cur);
            result = max(result, max_sofar);
        }

        return result;
    }
};