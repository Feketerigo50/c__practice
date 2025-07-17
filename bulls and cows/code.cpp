class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> counts(10, 0);
        vector<int> countg(10, 0);
        for(int i = 0; i < secret.length(); i++){
            if(secret[i] == guess[i]){
                bulls++;
            }else{
                counts[secret[i] - '0']++;
                countg[guess[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++){
            cows += min(counts[i], countg[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};