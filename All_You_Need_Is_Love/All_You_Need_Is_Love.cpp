#include <bits/stdc++.h>

using namespace std;

int euclidean(int a, int b){
    int tmp;
    if(a <= b){
        tmp = a;
        a = b;
        b = tmp;
    }
    while(b){
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int main()
{
    int i,n,n1,n2;
    string S1,S2;
    cin >> n;
    i = 0;
    while(i != n){
        cin >> S1;
        cin >> S2;
        n1 = stoi(S1,nullptr,2);
        n2 = stoi(S2,nullptr,2);
        if (euclidean(n1,n2) != 1){
            cout << "Pair #" << i+1 << ": All you need is love!" << endl;
        }else{
            cout << "Pair #" << i+1 << ": Love is not all you need!" << endl;
        }
        i++;
    }

    return 0;
}


//stoi(str,nullptr, 2) ==> 2進制字串 轉 10進制數字
//輾轉相除法找是不是互質即可。
//2^30 大概是10位數 ==> int 的範圍內。