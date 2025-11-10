class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(cap == 0 || !keyToVal.count(key)) return -1;

        increaseFreq(key);
        return keyToVal[key];
    }
    
    void put(int key, int value) {
        if(cap == 0) return;

        if(keyToVal.count(key)){
            keyToVal[key] = value;
            increaseFreq(key);
            return;
        }

        if(keyToVal.size() == cap){
            int rmKey = freqToKey[minFreq].back();
            freqToKey[minFreq].pop_back();
            
            if(freqToKey[minFreq].empty()){
                freqToKey.erase(minFreq);
            }

            keyToVal.erase(rmKey);
            keyToFreq.erase(rmKey);
            keyIter.erase(rmKey);
        }
        
        keyToVal[key] = value;
        keyToFreq[key] = 1;
        minFreq = 1;
        freqToKey[1].push_front(key);
        keyIter[key] = freqToKey[1].begin();

        return;
    }

private:
    int cap;
    int minFreq;
    unordered_map<int, int> keyToVal;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, list<int>> freqToKey;
    unordered_map<int, list<int>::iterator> keyIter;

    void increaseFreq(int key){
        int freq = keyToFreq[key];
        auto it = keyIter[key];

        freqToKey[freq].erase(it);
        if(freqToKey[freq].empty()){
            freqToKey.erase(freq);
            if(freq == minFreq){
                minFreq++;
            }
        }

        keyToFreq[key] = freq + 1;
        freqToKey[freq + 1].push_front(key);
        keyIter[key] = freqToKey[freq + 1].begin();

        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */