#include <bits/stdc++.h>
using namespace std;


int main()
{
    int num,points;
    int line_count;
    bool insert_flag;
    cin >> num;
    while(num--){
        cin >> points;
        int point_table[2][points];
        int line_table[4][points*(points-1)/2];
        line_count = 0;
        for(int i = 0; i < points; i++){
            cin >> point_table[0][i] >> point_table[1][i];
        }
        int deltay,deltax;
        for(int i = 0; i < points; i++){
            for(int j = 0; j < points; j++){
                if(i == j){
                    continue;
                }
                deltay = point_table[1][j] - point_table[1][i];
                deltax = point_table[0][j] - point_table[0][i];
                insert_flag = true;
                for(int x = 0; x < line_count; x++){
                    if(deltax*line_table[3][x] == deltay*line_table[2][x]){
                        if((point_table[0][j] - line_table[0][x])*line_table[3][x] == (point_table[1][j] - line_table[1][x])*line_table[2][x]){
                            insert_flag = false;
                        }
                    }
                }
                if(insert_flag){
                    line_table[0][line_count] = point_table[0][j];
                    line_table[1][line_count] = point_table[1][j];
                    line_table[2][line_count] = deltax;
                    line_table[3][line_count++] = deltay;
                }
            }
        }
        cout << line_count << endl;
    }

    return 0;
}


// 同一條線 斜率相同 利用這概念分兩個table
// point_table 存所有的點 check 所有n(n-1)/2 條線
// line_table 存所有的 unique line 