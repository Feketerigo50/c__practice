class Solution {
    public int findNthDigit(int n) {
        long len = 1;
        long count = 9;
        long target = n;
        long start = 1;

        while(len * count < target){
            target -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        int offset = (int)((target - 1) / len);
        int idx = (int)((target - 1) % len);

        int num = (int)(start) + offset;
        String s = Integer.toString(num);

        return s.charAt(idx) - '0';
    }
}