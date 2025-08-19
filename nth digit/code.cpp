class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1;
        long long count = 9;
        long long target = n;
        long long start = 1;

        while(len * count < target){
            target -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        int offset = (target - 1) / len;
        int idx = (target - 1) % len;

        int num = start + offset;
        string s = to_string(num);

        return s[idx] - '0';
    }
};