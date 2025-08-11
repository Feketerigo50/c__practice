class RandomizedSet {
private:
    vector<int> storage;
    unordered_map<int, int> valtoindex;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valtoindex.count(val) == 1) return false;
        int n = storage.size();
        valtoindex[val] = n;
        storage.push_back(val);

        return true;
    }
    
    bool remove(int val) {
        if(valtoindex.count(val) == 0) return false;
        int tidx = valtoindex[val];
        int tval = storage.back();

        storage[tidx] = tval;
        valtoindex[tval] = tidx;

        storage.pop_back();
        valtoindex.erase(val);

        return true;
    }
    
    int getRandom() {
        int ridx = rand() % storage.size();
        return storage[ridx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */