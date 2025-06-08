class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<bool>> is_visited(n+2, vector<bool>(n+2, false));
        for(int i = 0; i < n+2; i++){
            is_visited[i][0] = true;
            is_visited[i][n+1] = true;
            is_visited[0][i] = true;
            is_visited[n+1][i] = true;
        }

        vector<vector<int>> matrix(n, vector<int>(n,0));
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int dir = 0;
        int row = 1;
        int col = 1;
        for(int i = 1; i < n*n+1; i++){
            matrix[row-1][col-1] = i;
            is_visited[row][col] = true;

            int new_row = row + dirs[dir].first;
            int new_col = col + dirs[dir].second;
            if(!is_visited[new_row][new_col]){
                row = new_row;
                col = new_col;
            }else{
                dir = (dir+1) % 4;
                row += dirs[dir].first;
                col += dirs[dir].second;
            }
        }

        return matrix;
    }
};