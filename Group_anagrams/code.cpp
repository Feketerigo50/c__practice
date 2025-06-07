class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> target_letter_used(26,0);
        vector<int> current_letter_used(26,0);
        vector<int> word_can_use(strs.size(),1);

        vector<vector<string>> groups;
        for(int i = 0; i < strs.size(); i++){
            if(word_can_use[i] == 0) continue;

            vector<string> group;
            group.push_back(strs[i]);
            word_can_use[i] = 0;
            for(int j = 0; j < 26; j++){
                target_letter_used[j] = 0;
            }
            for(int j = 0; j < strs[i].length(); j++){
                target_letter_used[strs[i][j] - 'a'] += 1;
            }

            for(int x = i+1; x < strs.size(); x++){
                if(word_can_use[x] == 0) continue;
                
                bool is_diff = false;
                for(int j = 0; j < 26; j++){
                    current_letter_used[j] = 0;
                }
                
                if(strs[x].length() != strs[i].length()){
                    is_diff = true;
                }else{
                    for(int z = 0; z < strs[x].length(); z++){
                        current_letter_used[strs[x][z] - 'a'] += 1;
                    }
                    for(int z = 0; z < 26; z++){
                        if(target_letter_used[z] != current_letter_used[z]){
                            is_diff = true;
                            break;
                        }
                    }
                }
                
                if(!is_diff){
                    group.push_back(strs[x]);
                    word_can_use[x] = 0;
                }
            }
            groups.push_back(group);
        }


        return groups;
    }
};