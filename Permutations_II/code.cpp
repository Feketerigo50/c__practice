class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        add_permute(permutations, nums, tmp, used);
        
        return permutations;
    }

    void add_permute(vector<vector<int>>& per, vector<int>& nums, vector<int>& tmp, vector<bool>& used){      
        if(tmp.size() == nums.size()){
            per.push_back(tmp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            used[i] = true;
            tmp.push_back(nums[i]);
            add_permute(per, nums, tmp, used);
            tmp.pop_back();
            used[i] = false;
        }
    }
};