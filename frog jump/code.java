class Solution {
    public boolean canCross(int[] stones) {
        Map<Integer, Set<Integer>> dp = new HashMap<>();
        
        for(int i = 0; i < stones.length; i++){
            dp.put(stones[i], new HashSet<>());
        }
        dp.get(0).add(0);

        for(int stone : stones){
            for(int k : dp.get(stone)){
                for(int step = k-1; step < k+2; step++){
                    if(step > 0 && dp.containsKey(stone + step)){
                        dp.get(stone + step).add(step);
                    }
                }
            }
        }

        return !dp.get(stones[stones.length-1]).isEmpty();
    }
}