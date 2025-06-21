class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int level = triangle.size();
        vector<int> dp = triangle[level-1];
        
        for(int row = level-2; row > -1; row--){
            for(int i = 0; i <= row; i++){
                dp[i] = triangle[row][i] + min(dp[i], dp[i+1]);
            }
        }

        return dp[0];
    }
};