class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        int remain = n;
        bool dirisleft = true;

        while(remain > 1){
            if(dirisleft || remain % 2 == 1){
                head += step;
            }
            remain /= 2;
            step *= 2;
            dirisleft = !dirisleft;
        }

        return head;
    }
};