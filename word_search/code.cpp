class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row+2, vector<bool>(col+2, true));
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                visited[i][j] = false;
            }
        }
        vector<pair<int,int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        function<bool(int, int, int)> DFS = [&](int x, int y, int word_index){

            if(board[x-1][y-1] == word[word_index]){
                if(word_index == word.length()-1) return true;

                visited[x][y] = true;
                for(int dir = 0; dir < 4; dir++){
                    int new_x = x + directions[dir].first;
                    int new_y = y + directions[dir].second;
                    if(!visited[new_x][new_y]){
                        if(DFS(new_x, new_y, word_index+1)){
                            return true;
                        }
                    }
                }
                visited[x][y] = false;
            }
            
            return false;
        };

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(DFS(i+1, j+1, 0)) return true;
            }
        }

        return false;
        
    }

};