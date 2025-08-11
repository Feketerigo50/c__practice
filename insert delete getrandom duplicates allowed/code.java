class RandomizedCollection {
    private List<Integer> nums;
    private Map<Integer, Set<Integer>> valtoidx;
    private Random rand;

    public RandomizedCollection() {
        nums = new ArrayList<>();
        valtoidx = new HashMap<>();
        rand = new Random();
    }
    
    public boolean insert(int val) {
        boolean result = !valtoidx.containsKey(val);
        if(result){
            valtoidx.put(val, new HashSet<>());
        }
        valtoidx.get(val).add(nums.size());
        nums.add(val);

        return result;
    }
    
    public boolean remove(int val) {
        if(!valtoidx.containsKey(val) || valtoidx.get(val).isEmpty()) return false;

        int remove_idx = valtoidx.get(val).iterator().next();
        int last_val = nums.get(nums.size()-1);

        nums.set(remove_idx, last_val);

        valtoidx.get(val).remove(remove_idx);
        valtoidx.get(last_val).add(remove_idx);
        valtoidx.get(last_val).remove(nums.size()-1);

        nums.remove(nums.size()-1);
        if(valtoidx.get(val).isEmpty()){
            valtoidx.remove(val);
        }

        return true;
    }
    
    public int getRandom() {
        return nums.get(rand.nextInt(nums.size()));
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */