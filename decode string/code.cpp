class Solution {
private:
    string dfs(string s){
        char curchar = s[0];
        string result = "";

        if(curchar == '['){
            int pair_count = 1;
            int idx = 0;
            while(pair_count != 0){
                idx++;
                if(s[idx] == ']') pair_count--;
                if(s[idx] == '[') pair_count++;
            }

            result = dfs(s.substr(1, idx-1));
        
        }else if(isdigit(curchar)){
            int idx = 0;
            while(isdigit(s[idx])){
                idx++;
            }
            string num = s.substr(0, idx);
            
            int pair_count = 1;
            int stidx = idx+1;
            while(pair_count != 0){
                idx++;
                if(s[idx] == ']') pair_count--;
                if(s[idx] == '[') pair_count++;
                if(pair_count == 0) break;
            }

            string tmp_res = dfs(s.substr(stidx, idx - stidx));
            for(int i = stoi(num); i > 0; i--){
                result += tmp_res;
            }
            if(idx+1 != s.size()){
                result += dfs(s.substr(idx+1));
            }

        }else{
            int idx = 0;
            while(idx < s.size()){
                if(isalpha(s[idx])){
                    result += s[idx];
                }else{
                    break;
                }
                idx++;
            }
            if(idx != s.size()){
                result = result + dfs(s.substr(idx));
            }
        }

        return result;
    }

public:
    string decodeString(string s) {
        return dfs(s);
    }
};