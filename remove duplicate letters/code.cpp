class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last_position(26, 0);
        int s_len = s.length();
        
        for(int idx = 0; idx < s_len; idx++){
            last_position[s[idx] - 'a'] = idx;
        }

        vector<bool> used(26, false);
        string result = "";
        for(int idx = 0; idx < s_len; idx++){
            char cur = s[idx];
            if(used[cur - 'a']) continue;
            
            while(!result.empty() &&
                result.back() > cur &&
                last_position[result.back() - 'a'] > idx){
                    used[result.back() - 'a'] = false;
                    result.pop_back();
            }
            
            result += cur;
            used[cur - 'a'] = true;
        }

        return result;
    }
};