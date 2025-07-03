class Trienode{
public:
    Trienode* children[26];
    bool isWord = false;

    Trienode(){
        for(int i = 0 ; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    Trienode* root;
public:
    Trie() {
        root = new Trienode();
    }
    
    void insert(string word) {
        Trienode* cur = root;
        int idx;
        for(auto c : word){
            idx = c - 'a';
            if(!cur->children[idx]){
                cur->children[idx] = new Trienode();
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        Trienode* cur = root;
        int idx;
        for(auto c : word){
            idx = c - 'a';
            if(!cur->children[idx]) return false;
            cur = cur->children[idx];
        }
        if(cur->isWord) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Trienode* cur = root;
        int idx;
        for(auto c : prefix){
            idx = c - 'a';
            if(!cur->children[idx]) return false;
            cur = cur->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */