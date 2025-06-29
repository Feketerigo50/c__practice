class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1 << n);
        for (int i = 0; i < (1 << n); ++i) {
            result[i] = i ^ (i >> 1);
        }
        return result;
    }
};