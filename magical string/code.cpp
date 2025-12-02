class Solution {
public:
    int magicalString(int n) {
        if(n <= 3) return 1;

        int head = 2;
        int tail = 3;
        int countOne = 1;
        int num = 1;
        vector<int> magic(n);

        magic[0] = 1;
        magic[1] = 2;
        magic[2] = 2;
        while(tail < n){
            int times = magic[head];
            for(int i = 0; i < times && tail < n; i++){
                magic[tail] = num;
                if(num == 1) countOne++;
                tail++;
            }

            num = 3 - num;
            head++;
        }

        return countOne;
    }
};