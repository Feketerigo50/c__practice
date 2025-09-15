class Solution {
    public int characterReplacement(String s, int k) {
        int[] count = new int[26];
        int max_Charlen = 0;
        int left = 0;
        int result = 0;

        for(int right = 0; right < s.length(); right++){
            count[s.charAt(right) - 'A']++;
            max_Charlen = Math.max(max_Charlen, count[s.charAt(right) - 'A']);

            while((right - left + 1) - max_Charlen > k){
                count[s.charAt(left) - 'A']--;
                left++;
            }

            result = Math.max(result, right - left + 1);
        }

        return result;
    }
}