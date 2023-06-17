#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    int tmp;
    string direction;
    while(cin >> num && num){
        int dice[6] = {1,6,2,5,3,4};
        //             上 下 北 南 西 東
        while(num--){
            cin >> direction;
            if( direction == "north"){
                tmp = dice[2];
                dice[2] = dice[0];
                dice[0] = dice[3];
                dice[3] = dice[1];
                dice[1] = tmp;
            }else if( direction == "east"){
                tmp = dice[5];
                dice[5] = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[1];
                dice[1] = tmp;
            }else if( direction == "west"){
                tmp = dice[4];
                dice[4] = dice[0];
                dice[0] = dice[5];
                dice[5] = dice[1];
                dice[1] = tmp;
            }else if( direction == "south"){
                tmp = dice[3];
                dice[3] = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[1];
                dice[1] = tmp;
            }
        }
        cout << dice[0] << endl;
    }

    return 0;
}
