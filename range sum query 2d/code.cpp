class NumMatrix {
private:
    vector<vector<int>> dp;
    int row;
    int col;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        for(int i = 0; i < row; i++){
            vector<int> tmp;
            int row_sum = 0;
            for(int y = 0; y < col; y++){
                tmp.push_back(matrix[i][y] + row_sum);
                row_sum += matrix[i][y];
            }
            dp.push_back(tmp);
        }
        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){
                dp[i][j] += dp[i-1][j];
            }
        }

        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int overlay_x = row1 - 1;
        int overlay_y = col1 - 1;
        int upper_x = row1 - 1;
        int upper_y = col2;
        int left_x = row2;
        int left_y = col1 - 1;

        int result = dp[row2][col2];
        if(upper_x >= 0){
            result -= dp[upper_x][upper_y];
        }
        if(left_y >= 0){
            result -= dp[left_x][left_y];
        }
        if(overlay_x >= 0 && overlay_y >= 0){
            result += dp[overlay_x][overlay_y];
        }

        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */