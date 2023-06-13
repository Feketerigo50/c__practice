#include <bits/stdc++.h>

using namespace std;

int input[21];
int dp[21][101];

void backpack(int item, int weight ){
    for(int x = 0; x < 21; x++){
        for(int y = 0; y < 101;y++){
            dp[x][y] = 0;
        }
    }
    for(int x = 1; x < item+1; x++){
        dp[x][input[x]] = 1;
    }
    dp[0][0] = 1;
    for(int x = 1; x < item+1; x++){
        for(int y = 0; y < weight+1; y++){
            if (y == 0){
                dp[x][y] = 1;
            }else{
                if((y-input[x]) >= 0){
                    dp[x][y] = (dp[x-1][y] || dp[x-1][y-input[x]]); 
                }else{
                    dp[x][y] = dp[x-1][y];
                }
            }
        }
    }
    return;
}

int main()
{
    int n = 0;
    cin >> n; 
    cin.get();
    char tmp[150];
    while(n--){
        cin.getline(tmp,150);
        int i = 0;
        int inputlen = 1;
        int sum = 0;
        while(1){
            string s="";
            while(tmp[i] != ' ' && tmp[i] != '\0'){
                s += tmp[i++];
            }
            input[inputlen++] = stoi(s,nullptr,10);
            sum += stoi(s,nullptr,10);
            if(tmp[i] == '\0'){
                break;
            }else{
                i++;
            }
        }
        if(sum%2){
            cout << "NO" << endl;
        }else{
            sum /= 2;
            backpack(inputlen-1,sum);
            if (dp[inputlen-1][sum]){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    
    
    return 0;
}