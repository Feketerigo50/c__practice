class Solution {
    public int findKthNumber(int n, int k) {
        long prefix = 1;
        k -= 1;
        while(k > 0){
            long steps = count(prefix, n);
            if(steps <= k){
                prefix++;
                k -= steps;
            }else{
                prefix *= 10;
                k--;
            }
        }

        return prefix;
    }

    private long count(long prefix, long n){
        long cur = prefix;
        long next = prefix+1;
        long step = 0L;
        while(cur <= n){
            step += Math.min(next, n+1) - cur;
            cur *= 10;
            next *= 10;
        }

        return step;
    }
}