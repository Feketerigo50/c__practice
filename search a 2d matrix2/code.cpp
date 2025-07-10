class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0;
        int y = matrix[0].size()-1;
        int cur = matrix[x][y];

        while(cur != target){
            if(cur > target){
                y -= 1;
            }else{
                x += 1;
            }
            if(x == matrix.size() || y == -1){
                return false;
            }else{
                cur = matrix[x][y];
            }
        }
        
        return true;
    }
};