#include <bits/stdc++.h>

using namespace std;


int main()
{
    char input[1025];
    stack <int> input_num;
    stack <char> input_operator;
    stack <int> num;
    char input_sequence[1025];
    int index,seq_index;
    int front_num,back_num;
    bool valid_flag;
    char curr_oper;
    string num_tmp;
    while(1){
        cin.getline(input,1025);
        if(input[0] == '.')
            break;
        index = 0;
        seq_index = 0;
        valid_flag = true;
        while(input[index] != '\0'){
            if(input[index] == ' '){
                index++;
            }else if(isdigit(input[index])){
                num_tmp = "";
                while(isdigit(input[index]))
                    num_tmp += input[index++];
                input_num.push(stoi(num_tmp,nullptr,10));
                input_sequence[seq_index++] = 'n';
            }else{
                input_operator.push(input[index++]);
                input_sequence[seq_index++] = 'o';
            }
        }
        --seq_index;
        while(seq_index != -1 && valid_flag){
            if(input_sequence[seq_index] == 'n'){
                num.push(input_num.top());
                input_num.pop();
            }else{
                curr_oper = input_operator.top();
                input_operator.pop();
                if(num.size() > 1){
                    front_num = num.top();
                    num.pop();
                    back_num = num.top();
                    num.pop();
                }else{
                    valid_flag = false;
                }
                if(curr_oper == '%'){
                    num.push(front_num % back_num);
                }else if(curr_oper == '*'){
                    num.push(front_num * back_num);
                }else if(curr_oper == '/'){
                    num.push(front_num / back_num);
                }else if(curr_oper == '+'){
                    num.push(front_num + back_num);
                }else if(curr_oper == '-'){
                    num.push(front_num - back_num);
                }
            }
            --seq_index;
        }
        if(num.size() > 1){
            valid_flag = false;
        }
        if(valid_flag){
            cout << num.top() << endl;
            num.pop();
        }else{
            cout << "illegal" << endl;
        }
    }

    return 0;
}
// 就stack 由右至左 簡單啦