class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 0;
        int write = 0;
        
        while(read < chars.size()){
            int count = 1;
            char cur = chars[read++];

            while(read < chars.size() && chars[read] == cur){
                read++;
                count++;
            }

            chars[write++] = cur;

            if(count != 1){
                for(char c : to_string(count)){
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};