#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while(cin >> n){
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        int mid1 = a[(n-1)/2];
        int mid2 = a[n/2];
        int countmid = 0;
        for(int i = 0; i < n;i++){
            if(a[i] == mid1 || a[i] == mid2){
                countmid++;
            }
        }
        cout << mid1 << " " << countmid << " " << mid2-mid1+1 << endl;
    }

    return 0;
}