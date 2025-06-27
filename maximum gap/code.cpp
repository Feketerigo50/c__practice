class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int n = nums.size();

        int max_n = *max_element(nums.begin(), nums.end());
        int min_n = *min_element(nums.begin(), nums.end());
        if(max_n == min_n) return 0;

        int bucket_size = ceil((double)(max_n - min_n) / (n - 1));
        int bucket_count = (max_n - min_n) / bucket_size + 1;

        vector<int> max_per_bucket(bucket_count, INT_MIN);
        vector<int> min_per_bucket(bucket_count, INT_MAX);
        vector<bool> isnum_per_bucket(bucket_count, false);
        
        for(auto num : nums){
            int idx = (num - min_n) / bucket_size;
            max_per_bucket[idx] = max(max_per_bucket[idx], num);
            min_per_bucket[idx] = min(min_per_bucket[idx], num);
            isnum_per_bucket[idx] = true;
        }

        int prev_max = min_n;
        int max_gap = 0;
        for(int i = 0; i < bucket_count; i++){
            if(!isnum_per_bucket[i]) continue;
            max_gap = max(max_gap, min_per_bucket[i] - prev_max);
            prev_max = max_per_bucket[i];
        }

        return max_gap;
    }
};