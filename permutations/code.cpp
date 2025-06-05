class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) { 
        vector<vector<int>> permutations;
        add_permute(permutations, nums, 0);
        
        return permutations;
    }

    void add_permute(vector<vector<int>>& per, vector<int>& nums, int cur){      
        if(cur == nums.size()){
            per.push_back(nums);
            return;
        }

        for(int i = cur; i < nums.size(); i++){
            swap(nums[cur], nums[i]);
            add_permute(per, nums, cur+1);
            swap(nums[cur], nums[i]);
        }
    }
};