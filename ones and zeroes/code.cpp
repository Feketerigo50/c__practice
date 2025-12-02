class Solution {
private:
    int maxLen = INT_MIN;
    int m;
    int n;

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        this->m = m;
        this->n = n;
        sort(strs.begin(), strs.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        
        dfs(strs, 0, 0, 0, 0);
        return maxLen;
    }

    void dfs(vector<string>& strs, int idx, int curLen, int curM, int curN){
        if(idx == strs.size()){
            maxLen = max(maxLen, curLen);
            return;
        }

        int tmpM = 0;
        int tmpN = 0;
        for(char c : strs[idx]){
            if(c == '0'){
                tmpM++;
            }else{
                tmpN++;
            }
        }

        if(curM + tmpM <= m && curN + tmpN <= n){
            dfs(strs, idx+1, curLen+1, curM+tmpM, curN+tmpN);
        }
        dfs(strs, idx+1, curLen, curM, curN);

        return;
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(string s : strs){
            int one = 0;
            int zero = 0;
            for(char c : s){
                (c == '0' ? zero : one) += 1;
            }

            for(int i = m; i >= zero; i--){
                for(int j = n; j >= one; j--){
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
                }
            }
        }
        
        return dp[m][n];
    }

};