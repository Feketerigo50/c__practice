class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int max_Charlen = 0;
        int left = 0;
        int result = 0;

        for(int right = 0; right < s.size(); right++){
            count[s[right] - 'A']++;
            max_Charlen = max(max_Charlen, count[s[right] - 'A']);

            while((right - left + 1) - max_Charlen > k){
                count[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
        }
        
        return result;
    }
};