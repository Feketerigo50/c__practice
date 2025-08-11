class Solution {
private:
    vector<int> nums;
    vector<int> origin;
    mt19937 gen{random_device{}()};
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->origin = nums;    
    }
    
    vector<int> reset() {
        nums = origin;
        return nums;
    }
    
    vector<int> shuffle() {
        for (int i = nums.size() - 1; i > 0; --i) {
            uniform_int_distribution<int> dist(0, i);
            int j = dist(gen);
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */