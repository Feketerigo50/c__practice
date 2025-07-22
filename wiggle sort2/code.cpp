
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto medium = nums.begin() + n/2;
        nth_element(nums.begin(), medium, nums.end());
        int mid = *medium;

        auto zigzagindex = [&](int i){
            return (1 + 2*i) % (n | 1);
        };

        int i = 0; 
        int j = 0; 
        int k = n - 1;
        while(j <= k){
            if(nums[zigzagindex(j)] > mid ){
                swap(nums[zigzagindex(i++)], nums[zigzagindex(j++)]);
            }else if(nums[zigzagindex(j)] < mid){
                swap(nums[zigzagindex(j)], nums[zigzagindex(k--)]);
            }else{
                j++;
            }
        }
        return;
    }
};