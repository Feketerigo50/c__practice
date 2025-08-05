class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> min_heap;

        for(int i = 0; i < nums2.size() && i < k; i++){
            min_heap.push({nums1[0] + nums2[i], 0, i});
        }

        while(result.size() < k){
            auto [sum, idx1, idx2] = min_heap.top();
            min_heap.pop();
            result.push_back({nums1[idx1], nums2[idx2]});
            
            if(idx1 + 1 < nums1.size()){
                min_heap.push({nums1[idx1+1] + nums2[idx2], idx1+1, idx2});
            }
        }

        return result;
    }
};