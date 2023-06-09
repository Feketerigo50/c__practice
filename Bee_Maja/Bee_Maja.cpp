#include <bits/stdc++.h>

using namespace std;

struct Node{
    int x;
    int y;
}Nodes[100000];

void init(){
    Nodes[0].x = 0;
    Nodes[0].y = 0;
    int repeat = 1;
    int count = 1;
    int tmp;
    while(count < 100000){
        tmp = repeat;
        while(tmp--){
            Nodes[count].x = Nodes[count-1].x;
            Nodes[count].y = Nodes[count-1].y+1;
            count++;
        }
        tmp = repeat-1;
        while(tmp--){
            Nodes[count].x = Nodes[count-1].x-1;
            Nodes[count].y = Nodes[count-1].y+1;
            count++;
        }
        tmp = repeat;
        while(tmp--){
            Nodes[count].x = Nodes[count-1].x-1;
            Nodes[count].y = Nodes[count-1].y;
            count++;
        }
        tmp = repeat;
        while(tmp--){
            Nodes[count].x = Nodes[count-1].x;
            Nodes[count].y = Nodes[count-1].y-1;
            count++;
        }
        tmp = repeat;
        while(tmp--){
            Nodes[count].x = Nodes[count-1].x+1;
            Nodes[count].y = Nodes[count-1].y-1;
            count++;
        }
        tmp = repeat;
        while(tmp--){
            Nodes[count].x = Nodes[count-1].x+1;
            Nodes[count].y = Nodes[count-1].y;
            count++;
        }
    }
}


int main()
{
    init();
    int n;
    while(cin >> n){
        cout << Nodes[n-1].x << " " << Nodes[n-1].y << endl;
    }
    return 0;
}


//好像是單純就照順序打 恩