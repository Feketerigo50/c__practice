class Solution {
public:
    int dp_solution(vector<int>& nums){
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        int result = 1;
        for(int i = 0; i < dp.size(); i++){
            result = max(result, dp[i]);
        }

        return result;
    }


    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for(int i = 0; i < nums.size(); i++){
            auto it = lower_bound(LIS.begin(), LIS.end(), nums[i]);
            if(it == LIS.end()){
                LIS.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
        }

        return LIS.size();
    }
};