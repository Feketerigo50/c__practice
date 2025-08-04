class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = INT_MIN;

        for(int top = 0; top < m; top++){
            vector<int> colSum(n,0);
            for(int buttom = top; buttom < m; buttom++){
                for(int i = 0; i < n; i++){
                    colSum[i] += matrix[buttom][i];
                }

                set<int> prefixSet;
                int prefix = 0;
                prefixSet.insert(0);

                for(int i = 0; i < n; i++){
                    prefix += colSum[i];
                    auto it = prefixSet.lower_bound(prefix - k);
                    if(it != prefixSet.end()){
                        res = max(res, prefix - *it);
                    }
                    prefixSet.insert(prefix);
                }
            }
        }

        return res;
    }
};