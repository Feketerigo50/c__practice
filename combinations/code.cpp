class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tmp_com;

        function<void(int)> trace = [&](int start){
            if(tmp_com.size() == k){
                result.push_back(tmp_com);
                return;
            }

            for(int i = start; i <= n - (k - tmp_com.size()) + 1 ; i++){
                tmp_com.push_back(i);
                trace(i+1);
                tmp_com.pop_back();
            }
            return;
        };

        trace(1);

        return result;
    }
};