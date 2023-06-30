#include <bits/stdc++.h>
using namespace std;


int main()
{
    int num,k;
    int output;
    while(cin >> num && num){
        k = 1;
        output = 0;
        while(output != 11){
            output = 0;
            for(int i = 2; i < num;i++){
                output = (output+k) % i;
            }
            ++k;
        }
        cout << --k <<endl;
    }

    return 0;
}


// Josephus Problem 變形
// g(n,k) 代表總共有n個人從1開始照順序報數，數到第k個就自殺 一直數到最後活著的那個是誰
// g(1,k) = 0                      ==> 記得編號要-1 
// g(n,k) = (g(n-1,k)+k)%n         ==> 記得n會迭代

// 原本第一個人是不會死，這題第一個人必先死 
// 所以當作n-1個自殺，最後一個要是11 (因為原本的13在無視第一個的情況-1，然後根據迭代公式編號要再-1)