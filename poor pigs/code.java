class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int round = minutesToTest/minutesToDie;

        while(Math.pow(round+1, pigs) < buckets){
            pigs++;
        }

        return pigs;
    }
}