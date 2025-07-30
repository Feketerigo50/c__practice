class Solution {
public:
    unordered_map<string, int> revWord;
    vector<vector<int>> result;

    bool isPalin(string word){
        int left = 0, right = word.length() - 1;
        while (left < right) {
            if (word[left++] != word[right--]) return false;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            revWord[tmp] = i;
        }

        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            for(int j = 0; j <= word.length(); j++){
                string prefix = word.substr(0, j);
                string suffix = word.substr(j);

                if(isPalin(prefix) && revWord.count(suffix) && revWord[suffix] != i){
                    result.push_back({revWord[suffix], i});
                }

                if(revWord.count(prefix) && revWord[prefix] != i && isPalin(suffix) && j != word.length()){
                    result.push_back({i, revWord[prefix]});
                }
            }
        }

        return result;
    }
};