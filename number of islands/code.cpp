class Solution {
public:
    void DFS(vector<vector<char>>& grid, int x, int y){
        int row = grid.size();
        int col = grid[0].size();

        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        stack<pair<int, int>> stk;
        stk.push({x, y});
        while(!stk.empty()){
            x = stk.top().first;
            y = stk.top().second;
            stk.pop();
            grid[x][y] = '0';
            for(int i = 0; i < 4; i++){
                int new_x = x + dirs[i].first;
                int new_y = y + dirs[i].second;
                if(new_x > -1 && new_x < row && new_y > -1 && new_y < col){
                    if(grid[new_x][new_y] == '1')
                        stk.push({new_x, new_y});
                }
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    result++;
                    DFS(grid, i, j);
                }
            }
        }

        return result;
    }
};