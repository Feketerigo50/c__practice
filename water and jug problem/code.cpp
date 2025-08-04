class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target > x + y) return false;
        if(target % gcd(x,y) == 0) return true;

        return false;
    }

    int gcd(int x, int y){
        return y == 0 ? x : gcd(y, x % y);
    }
};