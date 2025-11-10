class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(s1.size()*n1 < s2.size()*n2) return 0;

        int s1Cnt = 0;
        int s2Cnt = 0;
        int idx = 0;
        unordered_map<int, pair<int, int>> recall;

        while(true){
            s1Cnt++;
            for(char c : s1){
                if(c == s2[idx]){
                    idx++;
                    if(idx == s2.size()){
                        idx = 0;
                        s2Cnt++;
                    }
                }
            }

            if(s1Cnt == n1) return s2Cnt/n2;

            if(recall.count(idx)){
                auto [cycle1, cycle2] = recall[idx];
                int remain = n1 - s1Cnt;
                int cycle = remain / (s1Cnt - cycle1);

                s1Cnt += cycle * (s1Cnt - cycle1);
                s2Cnt += cycle * (s2Cnt - cycle2);
            }else{
                recall[idx] = {s1Cnt, s2Cnt};
            }

            if(s1Cnt == n1) return s2Cnt/n2;
        }
        
        return 0;
    }
};