#include <bits/stdc++.h>
using namespace std;

int main()
{
    int milk_amount,container_amount;
    int milk_sum,biggest_milk;
    int container_capacity,container_count;
    while( cin >> milk_amount && milk_amount){
        cin >> container_amount;
        int milks[milk_amount];
        milk_sum = 0;
        biggest_milk = 0;
        for(int i = 0; i < milk_amount; i++){
            cin >> milks[i];
            milk_sum += milks[i];
            if(milks[i] > biggest_milk){
                biggest_milk = milks[i];
            }
        }

        // Find smallest container capacity that satisfied container amount
        int left = biggest_milk;
        int right = milk_sum;
        while( left < right ){
            container_capacity = (left+right)/2;
            milk_sum = 0;
            container_count = 0;
            for(int i = 0; i < milk_amount; i++){
                milk_sum += milks[i];
                if(milk_sum > container_capacity){
                    milk_sum = milks[i];
                    container_count++;
                }else if(milk_sum  == container_capacity){
                    milk_sum = 0;
                    container_count++;
                }
            }
            
            if( milk_sum > 0){
                container_count++;
            }
            if(container_count > container_amount){
                left = container_capacity+1;
            }else{
                right = container_capacity;
            }
        }
        cout << left << endl;
    }

    return 0;
}

