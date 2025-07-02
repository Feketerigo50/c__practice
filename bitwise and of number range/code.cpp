class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int digits = 0;
        while(left != right){
            left >>= 1;
            right >>= 1;
            digits++;
        }
        return left << digits;
    }
};