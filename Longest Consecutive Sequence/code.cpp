class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> num_set(nums.begin(), nums.end());
        
        int max_length = 0;
        for(int num : num_set){
            int length = 0;
            if(num_set.count(num-1) == 0){
                length = 1;
                int tmp = num+1;
                while(num_set.count(tmp)){
                    length++;
                    tmp++;
                }

                max_length = max({length, max_length});
            }
        }

        return max_length;
    }
};