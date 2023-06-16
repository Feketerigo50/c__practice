#include <bits/stdc++.h>
using namespace std;

struct Node{
    int x;
    int y;
};

int main()
{
    int num;
    cin >> num;
    int world = 1;
    while(num--){
        int row,col;
        cin >> row >> col;
        cin.ignore();
        int origin_map[row+2][col+2];
        int search_map[row+2][col+2];
        
        char input[col+1];
        for(int i = 0; i < row+2;i++){
            if(i != 0 && i != row+1){
                cin.getline(input,col+1);
            }
            for(int j = 0;j < col+2;j++){
                if(i == 0 || i == row+1 || j == 0 || j == col+1){
                    origin_map[i][j] = 50;
                    search_map[i][j] = 0;
                }else{
                    origin_map[i][j] = input[j-1] - 'a' +1;
                    search_map[i][j] = 1;
                }
            }
        }
        
        int counter[27] = {0};
        stack<Node> bfslist;
        
        for(int i = 1; i < row+1;i++){
            for(int j = 1;j < col+1;j++){
                // BFS
                if(search_map[i][j]){
                    counter[origin_map[i][j]] += 1;
                    struct Node tmp,current;
                    tmp.x = i;
                    tmp.y = j;
                    bfslist.push(tmp);
                    while(!bfslist.empty()){
                        tmp = bfslist.top();
                        bfslist.pop();
                        search_map[tmp.x][tmp.y] = 0;
                        if(origin_map[tmp.x-1][tmp.y] == origin_map[i][j] && search_map[tmp.x-1][tmp.y] ){
                           current.x = tmp.x-1;
                           current.y = tmp.y;
                           bfslist.push(current);
                        }
                        if(origin_map[tmp.x+1][tmp.y] == origin_map[i][j] && search_map[tmp.x+1][tmp.y] ){
                           current.x = tmp.x+1;
                           current.y = tmp.y;
                           bfslist.push(current);
                        }
                        if(origin_map[tmp.x][tmp.y-1] == origin_map[i][j] && search_map[tmp.x][tmp.y-1] ){
                           current.x = tmp.x;
                           current.y = tmp.y-1;
                           bfslist.push(current);
                        }
                        if(origin_map[tmp.x][tmp.y+1] == origin_map[i][j] && search_map[tmp.x][tmp.y+1] ){
                           current.x = tmp.x;
                           current.y = tmp.y+1;
                           bfslist.push(current);
                        }
                    }
                }
            }
        }
        
        cout << "Wrold #" << world << ":" << endl;
        for(int i = *max_element(counter,counter+27); i > 0; i--){
            for(int j = 1; j < 27; j++){
                if(counter[j] == i){
                    int out = 'a' - 1;
                    char output = j+out;
                    cout << output << ": " << i << endl;
                }
            }
        }
        
        world++;
    }

    return 0;
}

// 其實本來是想用DFS，但寫的時候不知覺就寫成BFS，想了想結果一樣就沒改回來。
// C++內建 Stack ，max_element(a,a+n)
// int tmp = char - '0' 可取得字元ASCII