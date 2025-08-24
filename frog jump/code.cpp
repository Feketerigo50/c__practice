class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        dp[0] = {0};

        for(int i = 1; i < stones.size(); i++){
            dp[stones[i]] = {};
        }

        for(int stone : stones){
            for(auto k : dp[stone]){
                for(int step = k-1; step < k+2; step++){
                    if(step > 0 && dp.count(stone + step) == 1){
                        dp[stone + step].insert(step);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};