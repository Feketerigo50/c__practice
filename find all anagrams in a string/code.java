class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int s_len = s.length();
        int p_len = p.length();

        if(s_len < p_len) return new ArrayList<>();

        int[] cnt_s = new int[26];
        int[] cnt_p = new int[26];
        
        List<Integer> result = new ArrayList<>();

        for(char c : p.toCharArray()){
            cnt_p[c - 'a']++;
        }

        for(int i = 0; i < p_len; i++){
            cnt_s[s.charAt(i) - 'a']++;
        }

        boolean if_fit = true;
        for(int i = 0; i < 26; i++){
            if(cnt_s[i] != cnt_p[i]) if_fit = false;
        }
        if(if_fit) result.add(0);

        for(int i = p_len; i < s_len; i++){
            cnt_s[s.charAt(i) - 'a']++;
            cnt_s[s.charAt(i - p_len) - 'a']--;

            if_fit = true;
            for(int j = 0; j < 26; j++){
                if(cnt_s[j] != cnt_p[j]) if_fit = false;
            }
            if(if_fit) result.add(i - p_len + 1);
        }

        return result;
    }
}