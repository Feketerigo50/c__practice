class Solution {
public:
    string frequencySort(string s) {
        map<char, int> counter;

        for(char c : s){
            counter[c]++;
        }

        vector<pair<char,int>> freq(counter.begin(), counter.end());

        sort(freq.begin(), freq.end(), [](auto &a, auto &b){
           return a.second > b.second;
        });

        string result = "";
        for(auto pair : freq){
            string tmp = "";
            for(int i = 0; i < pair.second; i++){
                tmp += pair.first;
            }

            result += tmp;
        }

        return result;
    }
};