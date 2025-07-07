class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char pre_op = '+';
        int idx = 0;
        int num = 0;
        while(idx <= s.length()){
            if(idx < s.length())
                num = getNum(s, idx);

            if(pre_op == '+'){
                stk.push(num);
            }else if(pre_op == '-'){
                stk.push(-num);
            }else if(pre_op == '*'){
                int tmp = stk.top();
                stk.pop();
                stk.push(tmp*num);
            }else if(pre_op == '/'){
                int tmp = stk.top();
                stk.pop();
                stk.push(tmp/num);
            }
            pre_op = s[idx++];
        }

        int result = 0;
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        
        return result;
    }

    int getNum(string& expr, int& start){
        int num = 0;
        while(expr[start] == ' '){
            start++;
        }

        while(start < expr.length() && expr[start] != ' ' && expr[start] != '+' && expr[start] != '-' && expr[start] != '*' && expr[start] != '/'){
            num = 10*num + (expr[start] - '0');
            start++;
        }

        while(start < expr.length() && expr[start] == ' '){
            start++;
        }
        return num;
    }
};