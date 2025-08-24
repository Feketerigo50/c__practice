class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        
        for(char ch : num){
            while(!stk.empty() && k > 0 && stk.top() > ch){
                stk.pop();
                k--;
            }
            stk.push(ch);
        }

        while(k > 0 && !stk.empty()){
            k--;
            stk.pop();
        } 

        string result = "";
        while(!stk.empty()){
            char ch = stk.top();
            stk.pop();
            result.push_back(ch);
        }
        reverse(result.begin(), result.end());

        int i = 0;
        while(result[i] == '0' && i < result.size()) i++;

        result = result.substr(i);

        return result.empty() ? "0" : result;

    }
};