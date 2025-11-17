class Solution {
public:
    bool dfs(vector<int>& sticks, int idx, vector<int>& side4, int target){
        if(idx == sticks.size()){
            return side4[0] == target &&
                    side4[1] == target &&
                    side4[2] == target &&
                    side4[3] == target;
        }

        for(int i = 0; i < 4; i++){
            if(side4[i] + sticks[idx] > target) continue;

            bool need_cut = false;
            for(int j = 0; j < i; j++){
                if(side4[i] == side4[j]){
                    need_cut = true;
                    break;
                }
            }
            if(need_cut) continue;

            side4[i] += sticks[idx];
            if(dfs(sticks, idx+1, side4, target)) return true;
            side4[i] -= sticks[idx];
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if(n < 4) return false;

        int sum = 0;
        for(int len : matchsticks){
            sum += len;
        }
        if(sum % 4 != 0) return false;

        vector<int> side4(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(matchsticks, 0, side4, sum/4);
    }
};