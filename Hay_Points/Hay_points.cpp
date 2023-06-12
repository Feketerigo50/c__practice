#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n = 0;
    cin >> m >> n;
    map<string , int> dict;
    
    while(m--){
        string tmp = "";
        int price = 0;
        cin >> tmp >> price;
        dict[tmp] = price;
    }
    string tmp;
    int result = 0;
    while(cin >> tmp){
        if(tmp != "."){
            if(dict.count(tmp)){
                result += dict[tmp];
            }
        }else{
            cout << result << endl;
            result = 0;
        }
    }
    
    
    return 0;
}