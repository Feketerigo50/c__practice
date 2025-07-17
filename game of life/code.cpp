class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<pair<int, int>> directions = {
            {-1, -1} , {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };
        // live to dead -1, dead to live 2
        for(int x = 0; x < row; x++){
            for(int y = 0; y < col; y++){
                int next_x = 0;
                int next_y = 0;
                int live_neighbor = 0;
                for(int i = 0; i < directions.size(); i++){
                    next_x = x + directions[i].first;
                    next_y = y + directions[i].second;
                    if(next_x > -1 && next_x < row && next_y > -1 && next_y < col){
                        if(board[next_x][next_y] == 1 || board[next_x][next_y] == -1){
                            live_neighbor++;
                        }
                    }
                }
                if((live_neighbor < 2 || live_neighbor > 3) && board[x][y] == 1){
                    board[x][y] = -1;
                }
                if(live_neighbor == 3 && board[x][y] == 0){
                    board[x][y] = 2;
                }
            }
        }
        for(int x = 0; x < row; x++){
            for(int y = 0; y < col; y++){
                if(board[x][y] == 2){
                    board[x][y]--;
                }else if(board[x][y] == -1){
                    board[x][y]++;
                }
            }
        }


        return;
    }
};