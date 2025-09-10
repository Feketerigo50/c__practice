class Solution {
public:
    int strongPasswordChecker(string password) {
        bool has_lower = false;
        bool has_upper = false;
        bool has_digit = false;
        for(char c : password){
            if(islower(c)) has_lower = true;
            if(isupper(c)) has_upper = true;
            if(isdigit(c)) has_digit = true;
        }

        int miss_types = (!has_lower) + (!has_upper) + (!has_digit);
        int n = password.size();
        vector<int> repeat;

        int idx = 0;
        while(idx < n){
            char cur = password[idx];
            int tmp_len = 0;
            while(idx < n && cur == password[idx]){
                tmp_len++;
                idx++;
            }
            if(tmp_len > 2){
                repeat.push_back(tmp_len);
            }
        }

        int result = 0;
        if(n < 6){
            int insert = 6 - n;
            result = max(insert, miss_types);
        }else if(n < 20){
            int replace = 0;
            for(int len : repeat){
                replace += len/3;
            }
            result = max(replace, miss_types);
        }else{
            int deletion = n - 20;
            int mods[3] = {0,0,0};
            int replace = 0;
            for(int len : repeat){
                replace += len/3;
                mods[len%3]++;
            }

            int del = deletion;
            for(int i = 0; i < 3; i++){
                int use = min(mods[i], del/(i+1));
                replace -= use;
                del -= use*(i+1);
            }

            replace -= del / 3;

            result = deletion + max(replace, miss_types);
        }
        return result;

    }
};