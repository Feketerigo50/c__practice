class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> not_visited(matrix.size()+2, vector<bool>(matrix[0].size()+2, true));
        for(int i = 1; i < not_visited.size(); i++){
            not_visited[i][0] = false;
            not_visited[i][not_visited[0].size()-1] = false;
        }
        for(int i = 1; i < not_visited[0].size(); i++){
            not_visited[0][i] = false;
            not_visited[not_visited.size()-1][i] = false;
        }

        vector<int> spiral_array;
        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int row = 1;
        int col = 1;
        int direction = 0;
        int new_row,new_col;
        bool keep_going = true;
        while(keep_going){
            spiral_array.push_back(matrix[row-1][col-1]);
            not_visited[row][col] = false;

            new_row = row + directions[direction].first;
            new_col = col + directions[direction].second;
            if(not_visited[new_row][new_col]){
                row = new_row;
                col = new_col;
            }else{
                direction = (direction+1) % 4;
                row += directions[direction].first;
                col += directions[direction].second;
                if(!not_visited[row][col]) keep_going = false;
            }
           
        }


        return spiral_array;
    }

};