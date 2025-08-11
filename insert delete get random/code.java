class RandomizedSet {
    private List<Integer> nums;
    private Map<Integer, Integer> valtoindex;
    private Random rand;

    public RandomizedSet() {
        nums = new ArrayList<>();
        valtoindex = new HashMap<>();
        rand = new Random();
    }
    
    public boolean insert(int val) {
        if(valtoindex.containsKey(val)) return false;
        int n = nums.size();
        valtoindex.put(val, n);
        nums.add(val);

        return true;
    }
    
    public boolean remove(int val) {
        if(!valtoindex.containsKey(val)) return false;
        int tidx = valtoindex.get(val);
        int tval = nums.get(nums.size()-1);

        nums.set(tidx, tval);
        valtoindex.put(tval, tidx);

        nums.remove(nums.size()-1);
        valtoindex.remove(val);
        return true;
    }
    
    public int getRandom() {
        int ridx = rand.nextInt(nums.size());
        return nums.get(ridx);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */