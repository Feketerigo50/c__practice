class Solution {
public:
    int dp_solution(vector<int>& nums, int k){
        int n = nums.size();
        
        vector<long> prefix(n+1, 0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        
        vector<vector<long>> dp(n+1, vector<long>(k+1, LONG_MAX));
        dp[0][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int g = 1; g <= k; g++){
                for(int j = 0; j < i; j++){
                    long sum = prefix[i] - prefix[j];
                    dp[i][g] = min(dp[i][g], max(dp[j][g - 1], sum));
                }
            }
        }

        return dp[n][k];
    }

    bool if_can_split(vector<int>& nums, int k, int large_sum){
        long long cur_sum = 0;
        int groups = 1;
        for(int num : nums){
            if(cur_sum + num > large_sum){
                cur_sum = num;
                groups++;
                if(groups > k) return false;
            }else{
                cur_sum += num;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(), nums.end(), 0LL);
        long long result = right;

        while(left <= right){
            long long mid = left + (right - left)/2;
            if(if_can_split(nums, k, mid)){
                result = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return result;
        // return dp_solution(nums, k); O(n^2 * k);
    }
};