class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;

        function<void(int)> trace = [&](int start){
            if(path.size() == 4 && start == s.length()){
                result.push_back(join(path));
            }

            for(int i = 1; i < 4; i++){
                if(start+i > s.size()) break;

                string tmp = s.substr(start, i);
                if(is_valid(tmp)){
                    path.push_back(tmp);
                    trace(start+i);
                    path.pop_back();
                }
            }

        };

        trace(0);
        
        return result;
    }

    string join(vector<string> path){
        string res = path[0];
        for(int x = 1; x < 4; x++){
            res += "." + path[x];
        }
        return res;
    }

    bool is_valid(string seg){
        if(seg.length() == 0) return false;
        if(seg.length() > 1 && seg[0] == '0') return false;
        int t = stoi(seg);
        return t >= 0 && t < 256;
    }
};