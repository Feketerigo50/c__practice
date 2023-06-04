#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
    string directory;
    map<string, int> subdir;
}node[50000];

int sz;
char single_link[82];

void insert( char *line ){
    string tmp;
    int current = 0;
    int linelen = strlen(line);
    line[linelen++] = '\\';
    for(int i=0; i < linelen;i++){
        tmp = "";
        while(line[i] != '\\'){
            tmp = tmp+line[i++];
        }
        if(!node[current].subdir.count(tmp)){
            node[sz].directory = tmp;
            node[sz].subdir.clear();
            node[current].subdir[tmp] = sz++;
        }
        current = node[current].subdir[tmp];
    }
    return;
}

void printTree( int dad, int son){
    if(dad){
        for(int i=0;i < son;i++){
            cout << " ";
        }
        cout << node[dad].directory << endl;
    }
    for(map<string,int>::iterator i = node[dad].subdir.begin(); i != node[dad].subdir.end(); i++) {
        printTree(i->second,son+1);
    }
    return;
}

int main ()
{
    node[0].subdir.clear();
    sz = 1;
    int links = 0;
    cin >> links;
    while(links--){
        cin >> single_link;
        insert(single_link);
    }
    printTree(0,0);
    
    return 0;
}