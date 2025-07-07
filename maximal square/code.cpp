class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));

        int result = 0;
        for(int i = 1; i < matrix.size()+1; i++){
            for(int j = 1; j < matrix[0].size()+1; j++){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    result = max(dp[i][j], result);
                }
            }
        }

        return result*result;
    }
};