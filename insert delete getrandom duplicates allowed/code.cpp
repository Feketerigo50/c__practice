class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> valtoindex;
    mt19937 gen{random_device{}()};

public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool result = !valtoindex.count(val);
        valtoindex[val].insert(nums.size());
        nums.push_back(val);

        return result;
    }
    
    bool remove(int val) {
        if(!valtoindex.count(val) || valtoindex[val].empty()) return false;

        int remove_idx = *valtoindex[val].begin();
        int last_val = nums.back();

        nums[remove_idx] = last_val;

        valtoindex[val].erase(remove_idx);
        valtoindex[last_val].insert(remove_idx);
        valtoindex[last_val].erase(nums.size()-1);

        nums.pop_back();

        if(valtoindex[val].empty()){
            valtoindex.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<int> dist(0, nums.size() - 1);
        return nums[dist(gen)];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */