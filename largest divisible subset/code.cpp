class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        sort(nums.begin(), nums.end());

        vector<int> prevn(n, -1);
        vector<int> len(n, 1);
        int max_len = 0;
        int max_idx = -1;
        for(int i = 1; i < n; i++){
            for(int j = 0 ; j < i; j++){
                if(nums[i] % nums[j] == 0 && len[i] < len[j] + 1){
                    len[i] = len[j] + 1;
                    prevn[i] = j;
                }

                if(len[i] > max_len){
                    max_len = len[i];
                    max_idx = i;
                }
            }
        }

        vector<int> result;
        while(max_idx != -1){
            result.push_back(nums[max_idx]);
            max_idx = prevn[max_idx];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};