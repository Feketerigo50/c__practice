class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        int sum = 0;
        for(int i : nums){
            sum += i;
        }

        int max_sum = INT_MIN;
        int tsum = 0;
        for(int i = 0; i < nums.size(); i++){
            tsum += i*nums[i];
        }
        
        max_sum = max(max_sum, tsum);
        int n = nums.size();
        for(int i = 1; i < n; i++){
            tsum += sum - n*nums[n-i];
            max_sum = max(max_sum, tsum);
        }

        return max_sum;
    }
};