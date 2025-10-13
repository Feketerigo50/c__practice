class Solution {
    public int compress(char[] chars) {
        int write = 0;
        int read = 0;
        
        while(read < chars.length){
            int count = 1;
            char cur = chars[read++];

            while(read < chars.length && chars[read] == cur){
                read++;
                count++;
            }

            chars[write++] = cur;

            if(count > 1){
                for(char c : Integer.toString(count).toCharArray()){
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
}