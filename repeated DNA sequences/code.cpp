class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, bool> DNA;
        vector<string> result;
        if(s.length() < 11) return result;
        
        for(int i = 0; i < s.length()-9; i++){
            string cur_dna = s.substr(i, 10);
            if(DNA.find(cur_dna) != DNA.end()){
                if(DNA[cur_dna] == false)
                    result.push_back(cur_dna);
                DNA[cur_dna] = true;
            }else{
                DNA[cur_dna] = false;
            }
        }

        return result;
    }
};