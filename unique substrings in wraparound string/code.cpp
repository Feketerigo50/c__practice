class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int dp[26] = {0};
        int maxlen = 1;

        dp[s[0] - 'a'] = 1;
        for(int i = 1; i < s.size(); i++){
            if(((s[i] - s[i-1]) + 26) % 26 == 1){
                maxlen++;
            }else{
                maxlen = 1;
            }
            dp[s[i] - 'a'] = max(maxlen, dp[s[i] - 'a']);
        }

        int answer = 0;
        for(int i = 0; i < 26; i++){
            answer += dp[i];
        }

        return answer;
    }
};