class Solution {
    private boolean pac[][];
    private boolean atl[][];
    private int heights[][];
    private int row;
    private int col;
    private int dirs[] = {-1, 0, 1, 0, -1};

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        this.heights = heights;
        row = heights.length;
        col = heights[0].length;
        pac = new boolean[row][col];
        atl = new boolean[row][col];
        
        for(int i = 0; i < row; i++){
            dfs(i, 0, pac);
            dfs(i, col-1, atl);
        }

        for(int j = 0; j < col; j++){
            dfs(0, j, pac);
            dfs(row-1, j, atl);
        }

        List<List<Integer>> res = new ArrayList<>();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(pac[i][j] && atl[i][j]){
                    res.add(Arrays.asList(i, j));
                }
            }
        }

        return res;
    }

    private void dfs(int x, int y, boolean ocean[][]){
        ocean[x][y] = true;

        for(int i = 0; i < 4; i++){
            int next_x = x + dirs[i];
            int next_y = y + dirs[i+1];
            if(next_x < 0 || next_x >= row || next_y < 0 || next_y >= col) continue;
            if(ocean[next_x][next_y] == true) continue;
            
            if(this.heights[next_x][next_y] >= this.heights[x][y]){
                dfs(next_x, next_y, ocean);
            }
        }

        return;
    }
}