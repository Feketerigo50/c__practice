class Solution {
public:
    // static bool cmp(vector<int>& a, vector<int>& b){
    //     return a[0] > b[0];
    // }


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});

        vector<vector<int>> interval;
        interval.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            auto& last = interval.back();
            if(intervals[i][0] <= last[1]){
                last[1] = max(last[1], intervals[i][1]);
            }else{
                interval.push_back(intervals[i]);
            }
        }

        return interval;
    }


    
};