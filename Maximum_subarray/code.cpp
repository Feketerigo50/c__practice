class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = 0;

        // max_sum = O_n_solution(nums);
        int left = 0;
        int right = nums.size()-1;
        int mid = (left + right)/2;
        max_sum = O_nlogn_sol(nums, left, mid, right);

        return max_sum;

    }

    int O_n_solution(vector<int>& ns){
        int max_n = ns[0];
        int tmp_max = ns[0];

        for(int i = 1; i < ns.size(); i++){
            tmp_max = max(tmp_max + ns[i], ns[i]);
            max_n = max(max_n, tmp_max);
        }

        return max_n;
    }

    int O_nlogn_sol(vector<int>& ns, int left, int mid, int right){
        if(left == right) return ns[left];
        
        int max_cross_left = INT_MIN;
        int tmp_sum = 0;
        for(int i = mid; i > left-1; i--){
            tmp_sum += ns[i];
            max_cross_left = max(max_cross_left, tmp_sum);
        }
        int max_cross_right = INT_MIN;
        tmp_sum = 0;
        for(int i = mid+1; i < right+1; i++){
            tmp_sum += ns[i];
            max_cross_right = max(max_cross_right, tmp_sum);
        }

        int max_left = O_nlogn_sol(ns, left, (left+mid)/2, mid);
        int max_right = O_nlogn_sol(ns, mid+1, (mid+1+right)/2, right);
        int max_cross = max_cross_left + max_cross_right;

        return max({max_left, max_right, max_cross});
    }
};