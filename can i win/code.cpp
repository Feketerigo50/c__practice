class Solution {
private:
    int n;
    map<int, bool> memo;

    bool canWin(int bitmask, int target){
        if(memo.count(bitmask)) return memo[bitmask];

        for(int i = 1; i <= n; i++){
            int choice = 1 << (i - 1);
            if(choice & bitmask) continue;

            if(i >= target || !canWin(bitmask | choice, target - i)){
                return memo[bitmask] = true;
            }
        }

        return memo[bitmask] = false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true;
        n = maxChoosableInteger;
        if(((n + 1)*n / 2) < desiredTotal) return false;

        memo.clear();
        return canWin(0, desiredTotal); 
    }
};