class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        if(s1.length() * n1 < s2.length() * n2) return 0;

        int s1Cnt = 0;
        int s2Cnt = 0;
        int idx = 0;
        Map<Integer, int[]> recall = new HashMap<>();

        while(true){
            s1Cnt++;
            for(int i = 0; i < s1.length(); i++){
                if(s1.charAt(i) == s2.charAt(idx)){
                    idx++;
                    if(idx == s2.length()){
                        idx = 0;
                        s2Cnt++;
                    }
                }
            }

            if(s1Cnt == n1) return s2Cnt/n2;

            if(recall.containsKey(idx)){
                int[] prev = recall.get(idx);
                int cycle1 = s1Cnt - prev[0];
                int cycle2 = s2Cnt - prev[1];

                int remain = n1 - s1Cnt;
                int period = remain / cycle1;

                s1Cnt += cycle1 * period;
                s2Cnt += cycle2 * period;
            }else{
                recall.put(idx, new int[]{s1Cnt, s2Cnt});
            }

            if(s1Cnt == n1) return s2Cnt/n2;
        }
        
    }
}