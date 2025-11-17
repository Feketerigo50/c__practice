class Solution {
    public int findSubstringInWraproundString(String s) {
        int[] dp = new int[26];
        int maxlen = 1;

        dp[s.charAt(0) - 'a'] = 1;
        for(int i = 1; i < s.length(); i++){
            if( (s.charAt(i) - s.charAt(i-1) + 26) % 26 == 1 ){
                maxlen++;
            }else{
                maxlen = 1;
            }

            dp[s.charAt(i) - 'a'] = Math.max(dp[s.charAt(i) - 'a'], maxlen);
        }

        int ans = 0;
        for(int tmp : dp){
            ans += tmp;
        }

        return ans;
    }
}