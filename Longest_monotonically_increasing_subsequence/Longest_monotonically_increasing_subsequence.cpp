#include <bits/stdc++.h>

using namespace std;

stack <int> output;
stack <int> tmpout;

void printPath(int x,int length[],int input[],vector<int> &rank){
    
    output.push(input[x]);
    
    if(length[x] == 1){
        int a,num_value;
        string value = "";
        while(!output.empty()){
            a = output.top();
            output.pop();
            tmpout.push(a);
            value += to_string(a);
        }
        num_value = stoi(value,nullptr,10);
        // cout << num_value << endl;
        rank.push_back(num_value);
        while(!tmpout.empty()){
            a = tmpout.top();
            tmpout.pop();
            output.push(a);
        }
        return;
    }
    
    for(int y = 0; y < x; y++){
        if(input[x] >= input[y]){
            if(length[x] == length[y]+1){
                printPath(y,length,input,rank);
                output.pop();
            }
        }
    }
    return;
}

void countPath(int x,int length[],int input[],int *counter){
    if(length[x] == 1){
        *counter += 1;
        return;
    }
    
    for(int y = 0; y < x; y++){
        if(input[x] >= input[y]){
            if(length[x] == length[y]+1){
                countPath(y,length,input,counter);
            }
        }
    }
    return;
}

int main()
{
    int num;
    cin >> num;
    int count,counter;
    int max;
    while(num--){
        cin >> count;
        int input[count];
        int length[count];
        max = 0;
        for(int i = 0;i<count;i++){
            cin >> input[i];
            length[i] = 1;
        }
        for(int i = 0;i<count;i++){
            for(int j = i+1; j < count;j++){
                if(input[j] >= input[i]){
                    if(length[j] < length[i]+1){
                        length[j] = length[i]+1;
                    }
                }
            }
        }
        
        counter = 0;
        for(int i = 0;i<count;i++){
            if(length[i] > max){
                max = length[i];
            }
        }
        for(int i = 0;i<count;i++){
            if(length[i] == max){
                countPath(i,length,input,&counter);
            }
        }
        cout << counter << endl;
        vector<int> rank;
        while(!output.empty())
            output.pop();
        for(int i = 0;i<count;i++){
            if(length[i] == max){
                printPath(i,length,input,rank);
                output.pop();
            }
        }
        sort(rank.begin(),rank.end(),greater <int>());
        // reverse(rank.begin(),rank.end());
        for(int i = 0;i < rank.size();i++){
            for(int j = max-1 ;j > -1;j--){
                int tmp = rank[i]/pow(10,j);
                cout << tmp << " ";
                rank[i] -= tmp*pow(10,j);
            }
            cout << endl;
        }
    }

    return 0;
}

// 這題用DP去找最長LCS，網路上都有教學
// 最討厭的是OUTPUT格式，他必須要照數字大到小排列出來
// 所以後半主要是花時間從字元轉數字，排列，再從數字轉字元
// 主要是 vector 傳入func 要vector <int> &v 因為會複製一份
// sort(begin,end,greater<int>()) 可以降冪
// vector.push_back() == python arr.append()
