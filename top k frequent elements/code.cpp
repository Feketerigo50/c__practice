class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> fre;
    //     for(auto num : nums){
    //         fre[num]++;
    //     }

    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
    //     for(auto [num, frec] : fre){
    //         min_heap.push({frec, num});
    //         if(min_heap.size() > k){
    //             min_heap.pop();
    //         }
    //     }

    //     vector<int> result;
    //     while(!min_heap.empty()){
    //         result.push_back(min_heap.top().second);
    //         min_heap.pop();
    //     }

    //     return result;
    // }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fre;
        for(auto num : nums){
            fre[num]++;
        }

        int n = nums.size();
        vector<vector<int>> buckets(n+1, vector<int>());
        for(auto [num, frec] : fre){
            buckets[frec].push_back(num);
        }

        vector<int> result;
        for(int i = n; i > 0; i--){
            if(k > 0){
                for(int j = 0; j < buckets[i].size() && k > 0; j++){
                    result.push_back(buckets[i][j]);
                    k--;
                }
            }else{
                break;
            }
        }

        return result;
    }
};