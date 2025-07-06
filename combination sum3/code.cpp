class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> tmp;
        
        function<void(int, int, int)> backtrace = [&](int target, int len, int start){
            if(target == 0 && len == 0){
                result.push_back(tmp);
                return;
            }

            if(target < 0 || len < 0 || start > target) return;

            for(int i = start; i < 10; i++){
                tmp.push_back(i);
                backtrace(target-i, len-1, i+1);
                tmp.pop_back();
            }
        };

        backtrace(n, k, 1);
        return result;
    }
};