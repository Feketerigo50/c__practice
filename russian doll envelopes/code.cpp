class Solution {

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        vector<int> LIS;
        for(auto env : envelopes){
            auto it = lower_bound(LIS.begin(), LIS.end(), env[1]);
            if(it == LIS.end()){
                LIS.push_back(env[1]);
            }else{
                *it = env[1];
            }
        }

        return LIS.size();
    }
};