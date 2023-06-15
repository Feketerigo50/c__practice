#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    while(cin >> num && num){
        
        int input[num];
        for(int i = 0;i < num; i++){
            cin >> input[i];
        }
        int flag = 1;
        sort(input,input+num);
        for(int i = num-1; i >= 0 && flag; i--){
            for(int j = 0 ; j < i && flag; j++){
                for(int x = j+1; x < i && flag; x++ ){
                    for(int y = x+1; y < i && flag; y++){
                        if(input[i] == input[j]+input[x]+input[y]){
                            cout << input[i] << endl;
                            flag = 0;
                        }
                    }
                }
            }
        }
        if(flag){
            cout << "no solution" << endl;
        }
    }

    return 0;
}