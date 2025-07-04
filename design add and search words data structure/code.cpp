class TraceNode{
public:
    TraceNode* child[26];
    bool isWord = false;

    TraceNode(){
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TraceNode* root;

public:
    WordDictionary() {
        root = new TraceNode();
    }
    
    void addWord(string word) {
        TraceNode* tmp = root;
        int idx;
        for(auto c : word){
            idx = c - 'a';
            if(!tmp->child[idx]){
                tmp->child[idx] = new TraceNode();
            }
            tmp = tmp->child[idx];
        }
        tmp->isWord = true;
        
        return;
    }
    
    bool search(string word) {
        return dfs(word, root, 0);
    }

    bool dfs(const string& word, TraceNode* node, int index){
        if(!node) return false;
        if(index == word.length()) return node->isWord;
        
        if(word[index] == '.'){
            for(int idx = 0; idx < 26; idx++){
                if(dfs(word, node->child[idx], index+1)) return true;
            }
            return false;
        }else{
            return dfs(word, node->child[word[index] - 'a'], index+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */