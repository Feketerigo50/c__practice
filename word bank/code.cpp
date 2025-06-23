class Solution {
public:
    bool trace(string& s, int start, unordered_set<string>& inDict, unordered_map<int, bool>& memo){
        if(start == s.length()) return true;
        if(memo.count(start)) return memo[start];

        for(int end = start + 1; end <= s.length(); end++){
            if(inDict.count(s.substr(start, end - start))){
                if(trace(s, end, inDict, memo)){
                    return memo[start] = true;
                }
            }
        }

        return memo[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> inDict(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        return trace(s, 0, inDict, memo);
    }
};
