class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.size() == 0) return 1;
        int last = b.back();
        b.pop_back();
        int part1 = modPow(a, last);
        int part2 = modPow(superPow(a, b), 10);

        return (part1* part2) % 1337;
    }

    int modPow(int a, int k){
        a %= 1337;
        int res = 1;
        for(int i = 0; i < k; i++){
            res = (res*a) % 1337;
        }

        return res;
    }
};