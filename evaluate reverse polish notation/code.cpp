class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int front, back;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                back = stk.top();
                stk.pop();
                front = stk.top();
                stk.pop();
                stk.push(front + back);
            }else if(tokens[i] == "-"){
                back = stk.top();
                stk.pop();
                front = stk.top();
                stk.pop();
                stk.push(front - back);
            }else if(tokens[i] == "*"){
                back = stk.top();
                stk.pop();
                front = stk.top();
                stk.pop();
                stk.push(front * back);
            }else if(tokens[i] == "/"){
                back = stk.top();
                stk.pop();
                front = stk.top();
                stk.pop();
                stk.push(front / back);
            }else{
                stk.push(stoi(tokens[i]));
            }
        }

        return stk.top();
    }
};