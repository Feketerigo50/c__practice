class Solution {
public:
    void DFS(int x, int y, vector<vector<bool>>& is_visit, vector<vector<char>>& map){
        if(map[x][y] != 'O' || is_visit[x][y]) return;
        
        is_visit[x][y] = true;
        
        vector<pair<int, int>> direction = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int i = 0; i < 4; i++){
            int next_x = x + direction[i].first;
            int next_y = y + direction[i].second;
            if(next_x > -1 && next_x < map.size() && next_y > -1 && next_y < map[0].size()){
                DFS(next_x, next_y, is_visit, map);
            }
        }

        return;
    }


    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> is_visited(row, vector<bool>(col, false));

        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O' && !is_visited[i][0]){
                DFS(i, 0, is_visited, board);
            }
            if(board[i][col-1] == 'O' && !is_visited[i][col-1]){
                DFS(i, col-1, is_visited, board);
            }
        }
        for(int i = 0; i < col; i++){
            if(board[0][i] == 'O' && !is_visited[0][i]){
                DFS(0, i, is_visited, board);
            }
            if(board[row-1][i] == 'O' && !is_visited[row-1][i]){
                DFS(row-1, i, is_visited, board);
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!is_visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};