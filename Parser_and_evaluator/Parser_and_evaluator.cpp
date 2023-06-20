#include <bits/stdc++.h>
using namespace std;


int priority(char ch){
    if(ch == '(' || ch == ')'){
        return 5;
    }else if(ch == '%'){
        return 4;
    }else if(ch == '*' || ch == '/'){
        return 3;
    }else if(ch == '-' || ch == '+'){
        return 2;
    }else if (isdigit(ch)) {
        return 1;
    }
    return 0;
}

int calculate(int a, int b,char calculater){
    // cout << a << " " << calculater << " " << b << endl;
    if(calculater == '%'){
        return a % b;
    }else if(calculater == '*'){
        return a * b;
    }else if(calculater == '/'){
        return a / b;
    }else if(calculater == '+'){
        return a + b;
    }else if(calculater == '-'){
        return a - b;
    }
    return 0;
}

int main()
{
    char input[1024];
    int counter = 1;
    int flag;
    int index;
    stack<int> numbers;
    stack<char> operators;
    while(true){
        cin.getline(input,1024);
        if(input[0] == '\0'){
            break;
        }
        // cout << input << endl;
        cout  << "case " << counter << ":" << endl;
        index = 0;
        if(input[0] != '-' && !isdigit(input[0]) && input[0] != '('){
            flag = 0;
        }else{
            flag = 1;
        }
        while(input[index] != '\0' && flag){
            flag = priority(input[index]);
            // cout << flag << "  :  " << input[index] << endl;
            if(flag == 5){
                if(input[index] == '('){
                    operators.push('(');
                }else{
                    if(operators.top() == '(' && !operators.empty()){
                        operators.pop();
                    }else{
                        flag = 0;
                    }
                }
            }else if(input[index] == '%' && input[index+1] == '0'){
                flag = 0;
            }else if(input[index] == '/' && input[index+1] == '0'){
                flag = 0;
            }else if(priority(input[index+1]) < 5 && priority(input[index+1]) > 1 && input[index+1] != '-'){
                if(flag > 1){
                    flag = 0;
                }
            }
            index++;
        }
        if( priority(input[index-1]) != 1 && input[index-1] != ')'){
            flag = 0;
        }
        
        if(!flag || !operators.empty()){
            cout << "syntactically incorrect" << endl;
        }else{
            // reformat Negative '-' to '_'
            char origin_input[1024];
            int origin_input_length = index++;
            index = 0;
            while(input[index] != '\0')
                origin_input[index] = input[index++];
            origin_input[index] = '\0';
            index = 0;
            int tmp_index = 0;
            while(input[index] != '\0'){
                if(input[index] == '-'){
                    if(index == 0){
                        input[index] = '_';
                    }else if(input[index-1] == '('){
                        input[index] = '_';
                    }else if(input[index-1] == ')' || isdigit(input[index-1]) ){
                        index++;
                        continue;
                    }else{
                        input[index++] = '(';
                        for(int i = 0; i<origin_input_length-tmp_index; i++){
                            input[index+i] = origin_input[tmp_index+i];
                        }
                        input[index++] = '_';
                        tmp_index++;
                        while(isdigit(input[index])){
                            index++;
                            tmp_index++;
                        }
                        input[index++] = ')';
                        for(int i = 0; i<origin_input_length-tmp_index; i++){
                            input[index+i] = origin_input[tmp_index+i];
                        }
                    }
                }
                index++;
                tmp_index++;
            }
            
            // cout << input << endl;
            // calculation
            index = 0;
            while(input[index] != '\0'){
                
                // cout << "--- " << input[index] << " --- " << endl;
                
                if(priority(input[index]) == 1){
                    string term = "";
                    while(isdigit(input[index])){
                        term += input[index++];
                    }
                    int term_num = stoi(term,nullptr,10);
                    if(numbers.empty() && !operators.empty() && operators.top() == '_'){
                        operators.pop();
                        term_num = 0-term_num;
                    }
                    numbers.push(term_num);
                }else{
                    if(input[index] == '_' || input[index] == '('){
                        operators.push(input[index]);
                    }else if(operators.empty()){
                        operators.push(input[index]);
                    }else if(priority(input[index]) > priority(operators.top())){
                        if(input[index] == ')'){
                            while(operators.top() != '('){
                                int b = numbers.top();
                                numbers.pop();
                                int a = numbers.top();
                                numbers.pop();
                                numbers.push(calculate(a,b,operators.top()));
                                operators.pop();
                            }
                            operators.pop();
                            index++;
                        }else{
                            operators.push(input[index]);
                        }
                    // }else if(priority(input[index]) < priority(operators.top())){
                    }else{
                        if(operators.top() != '('){
                            int b = numbers.top();
                            numbers.pop();
                            int a = numbers.top();
                            numbers.pop();
                            numbers.push(calculate(a,b,operators.top()));
                            operators.pop();
                        }
                        operators.push(input[index]);
                    }
                    index++;
                }
                
                // if(!numbers.empty()){
                //     cout << numbers.top() << "  :  ";
                // }else if(numbers.empty()){
                //     cout << "None  :  ";
                // }
                // if(!operators.empty()){
                //     cout << operators.top();
                // }else if(operators.empty()){
                //     cout << "None";
                // }
                // cout << endl;
                
            }
            
            // output
            while(!operators.empty()){
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                numbers.push(calculate(a,b,operators.top()));
                operators.pop();
            }
            cout << numbers.top() << endl;
            numbers.pop();
        }
        counter++;
        cout << endl;
    }

    return 0;
}


// 有註解可以取消，看計算過程更好trace
// 分三段: 第一段檢查合法格式，第二段將負號跟減號區分開來並重塑字串，第三段計算答案
// 解題基本觀念是由後序四則運算表示衍生而來
// 合法格式那邊可能有"沒有考慮到"的非法格式，但沒有測資幫我測我就懶得想