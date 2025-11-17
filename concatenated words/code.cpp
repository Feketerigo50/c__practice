class Solution {
private:
    struct Trie{
        bool is_word = false;
        struct Trie* children[26] = {nullptr};
    }root;

    bool canForm(const string& word, int start, int count){
        Trie* node = &root;
        for(int i = start; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(!node->children[idx]) return false;
            node = node->children[idx];
            if(node->is_word){
                if(i == word.size() - 1){
                    return count > 0;
                }else{
                    if(canForm(word, i+1, count+1)) return true;
                }
            }
        }
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;

        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });

        
        for(string word : words){
            if(canForm(word, 0, 0)){
                result.push_back(word);
            }else{
                int search_idx = 0;
                Trie* dummy = &root;
                while(search_idx < word.size()){
                    char cur = word[search_idx++];
                    if(!dummy->children[cur - 'a']){
                        dummy->children[cur - 'a'] = new Trie();
                    }
                    dummy = dummy->children[cur - 'a'];
                }
                dummy->is_word = true;
            }
        }

        return result;
    }
};