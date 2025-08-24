class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        using Cell = pair<int, pair<int,int>>;
        priority_queue<Cell, vector<Cell>, greater<Cell>> borders;

        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++){
            borders.push({heightMap[i][0], {i,0}});
            borders.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }

        for(int i = 0; i < n; i++){
            borders.push({heightMap[0][i], {0, i}});
            borders.push({heightMap[m-1][i], {m-1, i}});
            visited[0][i] = true;
            visited[m-1][i] = true;
        }

        int water = 0;
        vector<int> dir = {1,0,-1,0,1};

        while(!borders.empty()){
            auto [h, xy] = borders.top();
            borders.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = xy.first + dir[i];
                int ny = xy.second + dir[i+1];

                if(nx >= m || nx <= 0 || ny >= n || ny <= 0 || visited[nx][ny]) continue;
                visited[nx][ny] = true;

                int tmp = h - heightMap[nx][ny];
                if(tmp > 0){
                    water += tmp;
                }

                borders.push({ max(heightMap[nx][ny], h), {nx, ny}});
            }
        }


        return water;

    }
};