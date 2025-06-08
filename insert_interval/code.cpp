class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        int index = 0;
        while(index < intervals.size() && intervals[index][1] < newInterval[0]){
            result.push_back(intervals[index++]);
        }
        while(index < intervals.size() && newInterval[1] >= intervals[index][0] ){
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        result.push_back(newInterval);
        while(index < intervals.size()){
            result.push_back(intervals[index++]);
        }

        return result;
    }
};