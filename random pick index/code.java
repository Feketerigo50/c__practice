class Solution {
    private ArrayList<Integer> storage;
    private Random rand;

    public Solution(int[] nums) {
        storage = new ArrayList<>();
        rand = new Random();
        for(int i = 0; i < nums.length; i++){
            storage.add(nums[i]);
        }    
    }
    
    public int pick(int target) {
        int pickup = storage.get(0);
        int count = 0;

        for(int i = 0; i < storage.size(); i++){
            if(target == storage.get(i)){
                count++;
                if(rand.nextInt(count) == 0){
                    pickup = i;
                }
            }
        }

        return pickup;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */