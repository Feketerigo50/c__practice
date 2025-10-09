class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        
        map<char, int> counter;
        queue<char> que;

        for(char c : p){
            counter[c]++;
        }

        int idx = 0;
        int p_len = p.size();
        int s_len = s.size();
        vector<int> result;
        while(idx < s_len){
            if(que.size() == p_len){
                result.push_back(idx - p_len);
            }

            if(!counter.contains(s[idx])){
                while(!que.empty()){
                    char c = que.front();
                    que.pop();
                    counter[c]++;
                }
            }else{
                if(counter[s[idx]] == 0){
                    char c = que.front();
                    while(c != s[idx]){
                        que.pop();
                        counter[c]++;
                        c = que.front();
                    }
                    que.pop();
                    que.push(s[idx]);
                }else{
                    que.push(s[idx]);
                    counter[s[idx]]--;   
                }
            }

            idx++;
        }

        if(que.size() == p_len){
            result.push_back(idx - p_len);
        }

        return result;
    }
};