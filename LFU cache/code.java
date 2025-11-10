class LFUCache {
    private int cap;
    private int minFreq;
    private Map<Integer, Integer> keyToVal;
    private Map<Integer, Integer> keyToFreq;
    private Map<Integer, LinkedHashSet<Integer>> freqToKey;

    public LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        keyToVal = new HashMap<>();
        keyToFreq = new HashMap<>();
        freqToKey = new HashMap<>();
    }
    
    public int get(int key) {
        if(cap == 0 || !keyToVal.containsKey(key)) return -1;

        increaseFreq(key);
        return keyToVal.get(key);
    }
    
    public void put(int key, int value) {
        if(cap == 0) return;

        if(keyToVal.containsKey(key)){
            keyToVal.put(key, value);
            increaseFreq(key);
            return;
        }

        if(keyToVal.size() == cap){
            LinkedHashSet<Integer> list = freqToKey.get(minFreq);
            int rmkey = list.iterator().next();
            list.remove(rmkey);

            if(list.isEmpty()){
                freqToKey.remove(minFreq);
            }

            keyToFreq.remove(key);
            keyToVal.remove(key);
        }

        keyToVal.put(key, value);
        keyToFreq.put(key, 1);
        minFreq = 1;
        if(!freqToKey.containsKey(1)){
            freqToKey.put(1, new LinkedHashSet<>());
        }
        freqToKey.get(1).add(key);
        return;
    }

    private void increaseFreq(int key){
        int freq = keyToFreq.get(key);
        keyToFreq.put(key, freq + 1);

        freqToKey.get(freq).remove(key);
        if(freqToKey.get(freq).isEmpty()){
            freqToKey.remove(freq);
            if(freq == minFreq) minFreq++;
        }

        if(!freqToKey.containsKey(freq + 1)){
            freqToKey.put(freq + 1, new LinkedHashSet<>());
        }
        freqToKey.get(freq + 1).add(key);

        return;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */