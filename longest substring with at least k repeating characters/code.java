class Solution {
    public int longestSubstring(String s, int k) {
        if(k > s.length()) return 0;

        int[] dup_count = new int[26];
        int diff_limit = 0;
        int result = 0;
        
        for(char ch : s.toCharArray()){
            if(dup_count[ch - 'a'] == 0){
                dup_count[ch - 'a']++;
                diff_limit++;
            }
        }

        for(int diff_ch = 1; diff_ch <= diff_limit; diff_ch++){
            int left = 0;
            int right = 0;
            int diff_cur = 0;
            for(int i = 0; i < 26; i++){
                dup_count[i] = 0;
            }

            while(right != s.length()){
                char ch = s.charAt(right);
                
                if(dup_count[ch - 'a']++ == 0){
                    diff_cur++;
                    if(diff_cur > diff_ch){
                        while(dup_count[s.charAt(left) - 'a'] != 1){
                            dup_count[s.charAt(left) - 'a']--;
                            left++;
                        }
                        dup_count[s.charAt(left) - 'a']--;
                        diff_cur--;
                        left++;
                    }
                }

                if(diff_cur == diff_ch){
                    int window_dup_count = 0;
                    for(int i = 0; i < 26; i++){
                        if(dup_count[i] >= k){
                            window_dup_count += dup_count[i];
                        }else{
                            if(dup_count[i] != 0){
                                window_dup_count = 0;
                                break;
                            } 
                        }
                    }
                    result = Math.max(result, window_dup_count);
                }

                right++;
            }
        }

        return result;
    }
}