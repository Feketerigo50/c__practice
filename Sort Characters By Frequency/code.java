class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> counter = new HashMap<>();

        for(char c : s.toCharArray()){
            counter.put(c, counter.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<Map.Entry<Character, Integer>> max_heap = 
            new PriorityQueue<>((a,b) -> b.getValue() - a.getValue());

        max_heap.addAll(counter.entrySet());

        StringBuilder sb = new StringBuilder();
        while(!max_heap.isEmpty()){
            Map.Entry<Character, Integer> pair = max_heap.poll();
            sb.append(String.valueOf(pair.getKey()).repeat(pair.getValue()));
        }

        return sb.toString();
    }
}