class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;

        vector<int> masks(words.size(), 0);
        for(int i = 0; i < words.size(); i++){
            int mask = 0;
            for(int idx = 0; idx < words[i].size(); idx++){
                mask |= 1 << (words[i][idx] - 'a');
            }
            masks[i] = mask;
        }

        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                if((masks[i] & masks[j]) == 0){
                    result = max(result, (int)(words[i].length())*(int)(words[j].length()) );
                }
            }
        }

        return result;
    }
};