class Solution {
    static class Trie{
        Trie[] child = new Trie[2];
    }

    public int findMaximumXOR(int[] nums) {
        Trie root = new Trie();

        for(int num : nums){
            Trie node = root;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(node.child[bit] == null) node.child[bit] = new Trie();
                node = node.child[bit];
            }
        }

        int result = 0;
        for(int num : nums){
            Trie node = root;
            int xor_num = 0;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                int opp = bit ^ 1;
                if(node.child[opp] != null){
                    xor_num |= (1 << i);
                    node = node.child[opp];
                }else{
                    node = node.child[bit];
                }
            }

            result = Math.max(result, xor_num);
        }

        return result;
    }
}