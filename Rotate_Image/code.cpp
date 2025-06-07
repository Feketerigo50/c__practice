class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();

        for(int row = 0; row < length; row++){
            for(int col = row+1; col < length; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        for(int row = 0; row < length; row++){
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};