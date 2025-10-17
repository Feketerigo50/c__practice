class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_value = *min_element(nums.begin(), nums.end());

        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result += nums[i] - min_value;
        }

        return result;
    }
};