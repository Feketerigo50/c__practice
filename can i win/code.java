class Solution {
    private Map<Integer, Boolean> memo;
    private int n;

    private boolean canWin(int bitmask, int target){
        if(memo.containsKey(bitmask)) return memo.get(bitmask);

        for(int i = 1; i <= n; i++){
            int choice = 1 << (i - 1);
            if((choice & bitmask) != 0) continue;

            if(i >= target || !canWin(choice | bitmask, target - i)){
                memo.put(bitmask, true);
                return true;
            }
        }

        memo.put(bitmask, false);
        return false;
    }

    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true;
        n = maxChoosableInteger;
        if((n*(n+1) / 2) < desiredTotal) return false;

        memo = new HashMap<>();
        return canWin(0, desiredTotal);
    }
}