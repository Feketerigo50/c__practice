class Solution {
public:
    int findKthNumber(int n, int k) {
        long long prefix = 1;
        k -= 1;

        while(k > 0){
            long long steps = count(prefix, n);
            if(steps <= k){
                prefix++;
                k -= steps;
            }else{
                prefix *= 10;
                k -= 1;
            }
        }


        return prefix;
    }

    long long count(long long prefix, long long n){
        long long cur = prefix;
        long long next = prefix+1;
        long long step = 0;
        while(cur <= n){
            step += min(next, n+1) - cur;
            cur *= 10;
            next *= 10;
        }

        return step;
    }
};