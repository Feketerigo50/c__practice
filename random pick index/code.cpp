class Solution {
private:
    unordered_map<int, vector<int>> valtoidx;

public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            valtoidx[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        auto it = valtoidx[target].begin();
        int range = valtoidx[target].size();
        int pidx = rand() % range;
        return *(it + pidx);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */