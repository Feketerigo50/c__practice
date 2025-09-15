class Solution {
public:
    string originalDigits(string s) {
        vector<int> counter(26,0);
        for(char c : s){
            counter[c - 'a']++;
        }

        vector<int> ascend(10, 0);
        ascend[0] = counter['z'-'a'];
        ascend[2] = counter['w'-'a'];
        ascend[4] = counter['u'-'a'];
        ascend[6] = counter['x'-'a'];
        ascend[8] = counter['g'-'a'];

        ascend[1] = counter['o'-'a'] - ascend[0] - ascend[2] - ascend[4];
        ascend[3] = counter['r'-'a'] - ascend[4] - ascend[0];
        ascend[5] = counter['f'-'a'] - ascend[4];
        ascend[7] = counter['s'-'a'] - ascend[6];
        ascend[9] = counter['i'-'a'] - ascend[6] - ascend[5] - ascend[8];

        string result = "";
        for(int i = 0; i < 10; i++){
            while(ascend[i] > 0){
                result += to_string(i);
                ascend[i]--;
            }
        }

        return result;
    }
};