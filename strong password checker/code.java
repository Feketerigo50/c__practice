class Solution {
    public int strongPasswordChecker(String password) {
        boolean has_lower = false, has_upper = false, has_digit = false;
        for(char c : password.toCharArray()){
            if(Character.isLowerCase(c)) has_lower = true;
            if(Character.isUpperCase(c)) has_upper = true;
            if(Character.isDigit(c)) has_digit = true;
        }

        int miss_types = (has_upper ? 0 : 1) + (has_lower ? 0 : 1) + (has_digit ? 0 : 1);
        int n = password.length();

        int idx = 0;
        List<Integer> repeat = new ArrayList<>();
        while(idx < n){
            char cur = password.charAt(idx);
            int tmp_len = 0;
            while(idx < n && password.charAt(idx) == cur){
                idx++;
                tmp_len++;
            }
            if(tmp_len > 2) repeat.add(tmp_len);
        }

        int result = 0;
        if(n < 6){
            int insert = 6 - n;
            result = Math.max(insert, miss_types);
        }else if(n < 20){
            int replace = 0;
            for(int len : repeat){
                replace += len/3;
            }
            result = Math.max(replace, miss_types);
        }else{
            int deletion = n - 20;
            int mods[] = {0,0,0};
            int replace = 0;
            for(int len : repeat){
                replace += len/3;
                mods[len%3]++;
            }

            int del = deletion;
            for(int i = 0; i < 3; i++){
                int use = Math.min(mods[i], del/(i+1));
                replace -= use;
                del -= use*(i+1);
            }

            replace -= del/3;

            result = deletion + Math.max(replace, miss_types);
        }

        return result;       
    }
}