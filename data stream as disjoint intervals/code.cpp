class SummaryRanges {
private:
    set<pair<int, int>> interval;

public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto it = interval.lower_bound({value, value});

        if(it != interval.begin()){
            auto previt = prev(it);
            if(previt->first <= value && previt->second >= value) return;
        }
        
        if(it != interval.end() && it->first == value && it->second >= value) return;

        int start = value;
        int end = value;

        if(it != interval.begin()){
            auto previt = prev(it);
            if(previt->second == value-1){
                start = previt->first;
                interval.erase(previt);
            }
        }

        if(it != interval.end()){
            if(value+1 == it->first){
                end = it->second;
                interval.erase(it);
            }
        }
        
        interval.insert({start, end});
        
        
        return;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for(auto [start, end] : interval){
            result.push_back({start, end});
        }

        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */