class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp_com = {};
        
        function<void(int)> trace = [&](int start){
            result.push_back(tmp_com);

            for(int i = start; i < nums.size(); i++){
                tmp_com.push_back(nums[i]);
                trace(i+1);
                tmp_com.pop_back();
            }
            return;
        };

        
        trace(0);
        return result;
    }
};