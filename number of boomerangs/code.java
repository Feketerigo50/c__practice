class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int n = points.length;
        if(n < 3) return 0;

        int result = 0;
        for(int i = 0; i < n; i++){
            Map<Long, Integer> distance = new HashMap<>();

            for(int j = 0; j < n; j++){
                long dis_x = (long)points[i][0] - (long)points[j][0];
                dis_x *= dis_x;
                long dis_y = (long)points[i][1] - (long)points[j][1];
                dis_y *= dis_y;
                
                distance.put(dis_x + dis_y, distance.getOrDefault(dis_x + dis_y, 0) + 1);
            }

            for(var count : distance.values()){
                result += count * (count - 1);
            }
        }

        return result;
    }
}