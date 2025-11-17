class Solution {
    private int target;
    private int[] side4;
    private int[] sticks;

    public boolean makesquare(int[] matchsticks) {
        int n = matchsticks.length;
        if(n < 4) return false;

        int sum = 0;
        for(int num : matchsticks){
            sum += num;
        }
        if(sum % 4 != 0) return false;

        Arrays.sort(matchsticks);
        target = sum / 4;
        side4 = new int[4];
        sticks = matchsticks;
        return dfs(n-1);
    }

    private boolean dfs(int idx){
        if(idx < 0){
            return side4[0] == target &&
                    side4[1] == target &&
                    side4[2] == target &&
                    side4[3] == target;
        }

        for(int i = 0; i < 4; i++){
            if(side4[i] + sticks[idx] > target) continue;

            boolean skip = false;
            for(int j = 0; j < i; j++){
                if(side4[i] == side4[j]){
                    skip = true;
                    break;
                }
            }
            if(skip) continue;

            side4[i] += sticks[idx];
            if(dfs(idx-1)) return true;
            side4[i] -= sticks[idx];
        }

        return false;
    }
}