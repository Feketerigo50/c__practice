#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    long long S,D;
    long count = 1;
    while(cin >> S >> D){
        count = 1;
        while(1){
            D -= S;
            if(D<1){
                cout << S << endl;
                break;
            }else{
                S++;
            }
        }
    }

    return 0;
}

// 暴力解，一元二次不等式