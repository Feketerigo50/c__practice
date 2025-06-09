class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        int index = 0;

        while(index < path.length()){
            while(index < path.length() && path[index] == '/'){
                index++;
            }

            string dir = "";
            while(index < path.length() && path[index] != '/'){
                dir = dir + string(1, path[index]);
                index++;
            }
            if(dir == ".."){
                if(!stk.empty()){
                    stk.pop();
                }
            }else{
                if(dir != "." && dir != ""){
                    stk.push(dir);
                }
            }
        }

        string result = "";
        string tmp_dir;
        while (!stk.empty()) {
            tmp_dir = stk.top();
            stk.pop();
            result = "/" + tmp_dir + result;
        }

        if(result == ""){
            return "/";
        }
        return result;
    }
};