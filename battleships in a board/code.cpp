class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int result = 0;
        int row = board.size();
        int col = board[0].size();
        int dir[] = {-1,0, -1};

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'X'){
                    bool flag = true;
                    for(int k = 0; k < 2; k++){
                        int next_x = i + dir[k];
                        int next_y = j + dir[k+1];
                        if( next_x < 0 || next_x >= row || next_y < 0 || next_y >= col) continue;
                        if( board[next_x][next_y] == 'X') flag = false;
                    }
                    if(flag) result++;
                }
            }
        }

        return result;
    }
};