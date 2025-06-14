class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path = {};
        sort(nums.begin(), nums.end());

        function<void(int)> trace = [&](int start){
            result.push_back(path);

            for(int i = start; i < nums.size(); i++){
                if(i > start && nums[i] == nums[i-1]) continue;

                path.push_back(nums[i]);
                trace(i+1);
                path.pop_back();
            }
        };
        
        trace(0);

        return result;
    }
};