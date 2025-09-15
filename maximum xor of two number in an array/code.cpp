class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        struct Trie{
            Trie* child[2]{};
        };

        Trie* root = new Trie();

        auto insert = [&](int num){
            Trie* node = root;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(!node->child[bit]) node->child[bit] = new Trie();
                node = node->child[bit];
            } 
        };

        auto query = [&](int num){
            int xor_num = 0;
            Trie* node = root;
            for(int i = 31; i >=0; i--){
                int bit = (num >> i) & 1;
                int opp = bit ^ 1;
                if(node->child[opp]){
                    xor_num |= (1 << i);
                    node = node->child[opp]; 
                }else{
                    node = node->child[bit];
                }
            }

            return xor_num;
        };

        for(int num : nums){
            insert(num);
        }

        int result = 0;
        for(int num : nums){
            result = max(result, query(num));
        }

        return result;
    }
};