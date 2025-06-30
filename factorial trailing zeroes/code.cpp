class Solution {
public:
    int trailingZeroes(int n) {
        int count_2 = 0;
        int count_5 = 0;
        for(int i = 1; i < n+1; i++){
            int cur_num = i;
            while(cur_num % 2 == 0){
                count_2++;
                cur_num /= 2;
            }
            while(cur_num % 5 == 0){
                count_5++;
                cur_num /= 5;
            }
        }
        return min(count_2, count_5);
    }
};