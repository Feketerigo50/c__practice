class Solution {
public:
    void dfs(vector<vector<bool>>&map, vector<vector<int>>& heights, int x, int y){
        if(map[x][y] == true) return;
        
        map[x][y] = true;

        int row = heights.size();
        int col = heights[0].size();
        int dir[] = {1,0,-1,0,1};
        for(int i = 0; i < 4;i++){
            int next_x = x + dir[i];
            int next_y = y + dir[i+1];
            
            if(next_x < 0 || next_x >= row || next_y < 0 || next_y >= col){
                continue;
            }

            if(heights[next_x][next_y] >= heights[x][y])
                dfs(map, heights, next_x, next_y);
        }

        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pac(row, vector<bool>(col, false));
        vector<vector<bool>> atl(row, vector<bool>(col, false));

        for(int i = 0; i < row; i++){
            dfs(pac, heights, i, 0);
            dfs(atl, heights, i, col-1);
        }

        for(int i = 0; i < col; i++){
            dfs(pac, heights, 0, i);
            dfs(atl, heights, row-1, i);
        }

        vector<vector<int>> result;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(pac[i][j] && atl[i][j] && (pac[i][j] == atl[i][j])){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};