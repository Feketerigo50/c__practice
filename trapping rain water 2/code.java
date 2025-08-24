class Solution {
    static class Cell{
        int h,x,y;
        Cell(int h, int x, int y){
            this.h = h;
            this.x = x;
            this.y = y;
        }
    }
    
    public int trapRainWater(int[][] heightMap) {
        PriorityQueue<Cell> borders = new PriorityQueue<>((a,b) -> a.h - b.h);

        int m = heightMap.length;
        int n = heightMap[0].length;
        boolean[][] visited = new boolean[m][n];

        for(int i = 0; i < m; i++){
            borders.offer(new Cell(heightMap[i][0], i, 0));
            borders.offer(new Cell(heightMap[i][n-1], i, n-1));
            visited[i][0] = true;
            visited[i][n-1] = true;
        }

        for(int i = 0; i < n; i++){
            borders.offer(new Cell(heightMap[0][i], 0, i));
            borders.offer(new Cell(heightMap[m-1][i], m-1, i));
            visited[0][i] = true;
            visited[m-1][i] = true;
        }

        int water = 0;
        int[] dir = {1, 0, -1, 0, 1};
        while(!borders.isEmpty()){
            Cell cell = borders.poll();
            int h = cell.h;

            for(int i = 0; i < 4; i++){
                int nx = cell.x + dir[i];
                int ny = cell.y + dir[i+1];
                if(nx >= m || nx <= 0 || ny >= n || ny <= 0 || visited[nx][ny]) continue;
                visited[nx][ny] = true;

                int diffh = h - heightMap[nx][ny];
                if(diffh > 0) water += diffh;

                borders.offer(new Cell( Math.max(heightMap[nx][ny], h), nx, ny));
            }
        }
        
        return water;
    }
}