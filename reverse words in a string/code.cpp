class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        int index = 0;
        string word = "";
        s += " ";
        while(index < s.length()){
            if(s[index] == ' ' && word != ""){
                stk.push(word);
                word = "";
            }
            if(s[index] != ' '){
                word += s[index];
            }
            index++;
        }

        string result = stk.top();
        stk.pop();
        while(!stk.empty()){
            word = stk.top();
            stk.pop();
            result += " " + word;
        }


        return result;
    }
};