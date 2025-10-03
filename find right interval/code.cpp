class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> ascend;

        for(int i = 0; i < n; i++){
            ascend.push_back({intervals[i][0], i});
        }

        sort(ascend.begin(), ascend.end());

        vector<int> result(n, -1);
        for(int i = 0; i < n; i++){
            int end = intervals[i][1];
            auto it = lower_bound(ascend.begin(), ascend.end(), make_pair(end, 0));

            if(it != ascend.end()) result[i] = it->second;
        }

        return result;
    }
};