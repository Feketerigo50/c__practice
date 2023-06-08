#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<string, int> rank;
    
    while(cin >> n && n){
        while(n--){
            int course[5];
            string S="";
            for(int i=0;i<5;i++){
                cin >> course[i];
            }
            sort(course,course+5);
            for(int i=0;i<5;i++){
                S += to_string(course[i]);
            }
            if(rank.count(S)){
                rank[S] += 1;
            }else{
                rank[S] = 1;
            }
            if(n == 0){
                int max = 0;
                int ans = 0;
                for(map<string,int>::iterator i = rank.begin();i!=rank.end();i++){
                    if(i->second > max){
                        max = i->second;
                        ans = max;
                    }else if(i->second == max){
                        ans += max;
                    }
                }
                cout << ans << endl;
                rank.clear();
            }
        }
    }

    return 0;
}