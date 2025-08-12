class Solution {
    private List<Integer> nums;
    private void dfs(int cur, int n){
        if(cur > n) return;
        nums.add(cur);
        for(int i = 0; i < 10; i++){
            if(cur*10 + i > n) return;
            dfs(cur*10 + i, n);
        }

        return;
    }

    public List<Integer> lexicalOrder(int n) {
        nums = new ArrayList<>();

        for(int i = 1; i < 10; i++){
            dfs(i, n);
        }

        return nums;
    }
}