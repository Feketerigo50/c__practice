#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maps[20] = {
    0,1,5,2,8,3,9,2,8,7,
    7,8,4,7,3,8,4,1,5,4
};

int main()
{
    string input;
    while(cin >> input){
        int len = input.length();
        if (len == 1 && input == "0"){
            break;
        }
        int ans = input[len-1] - '0';
        if(len > 1){
            ans += (input[len-2] - '0')*10;
        }
        cout << maps[(ans%20+ans/20*4)%10] << endl;
        
    }

    return 0;
}

// 這題的重點在要假設 i = 10*a+b, 以及求尾數代表的意思就是 %10 
// 則可以得知題目所求為 sum(i^i) % 10, 帶入假設用二項式定理化簡
// 可得 ans = b^(10*a+b) %10
// 帶入 b = 0~9 求數列規律
// 可得20個數字(maps)+4規律，100個數字為一循環
// 故取 input 後兩位數字做運算即可