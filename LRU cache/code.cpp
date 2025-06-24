class LRUCache {
public:
    int cap;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        lru.splice(lru.begin(), lru, mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key]->second = value;
            lru.splice(lru.begin(), lru, mp[key]);
        }else{
            if(lru.size() == cap){
                auto tmp = lru.back();
                mp.erase(tmp.first);
                lru.pop_back();
            }
                lru.push_front({key, value});
                mp[key] = lru.begin();
        }

        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */