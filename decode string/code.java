class Solution {
    private String dfs(String s){
        char curchar = s.charAt(0);
        String result = "";

        if(curchar == '['){
            int pair_count = 1;
            int idx = 0;
            while(pair_count != 0){
                idx++;
                if(s.charAt(idx) == ']') pair_count--;
                if(s.charAt(idx) == '[') pair_count++;
            }

            result = dfs(s.substring(1, idx));
        
        }else if(Character.isDigit(curchar)){
            int idx = 0;
            while(Character.isDigit(s.charAt(idx))){
                idx++;
            }
            String num = s.substring(0, idx);
            
            int pair_count = 1;
            int stidx = idx+1;
            while(pair_count != 0){
                idx++;
                if(s.charAt(idx) == ']') pair_count--;
                if(s.charAt(idx) == '[') pair_count++;
                if(pair_count == 0) break;
            }

            String tmp_res = dfs(s.substring(stidx, idx));
            for(int i = Integer.parseInt(num); i > 0; i--){
                result += tmp_res;
            }
            if(idx+1 != s.length()){
                result += dfs(s.substring(idx+1));
            }

        }else{
            int idx = 0;
            while(idx < s.length()){
                if(Character.isLetter(s.charAt(idx))){
                    result += s.charAt(idx);
                }else{
                    break;
                }
                idx++;
            }
            if(idx != s.length()){
                result = result + dfs(s.substring(idx));
            }
        }

        return result;
    }
    public String decodeString(String s) {
        return dfs(s);   
    }
}