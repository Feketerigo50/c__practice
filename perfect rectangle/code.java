class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        long area = 0;
        int x1 = Integer.MAX_VALUE, y1 = Integer.MAX_VALUE;
        int x2 = Integer.MIN_VALUE, y2 = Integer.MIN_VALUE;
        Set<String> dup_corner = new HashSet<>();

        for(int i = 0; i < rectangles.length; i++){
            int tx1 = rectangles[i][0];
            int ty1 = rectangles[i][1];
            int tx2 = rectangles[i][2];
            int ty2 = rectangles[i][3];

            area += (long) (tx2 - tx1) * (ty2 - ty1);
            x1 = Math.min(x1, tx1);
            x2 = Math.max(x2, tx2);
            y1 = Math.min(y1, ty1);
            y2 = Math.max(y2, ty2);

            String[] corners = {
                tx1 + " " + ty1,
                tx1 + " " + ty2,
                tx2 + " " + ty1,
                tx2 + " " + ty2
            };

            for(String corn : corners){
                if(!dup_corner.add(corn)) dup_corner.remove(corn);
            }
        }

        if(dup_corner.size() != 4) return false;
        
        String[] corners = {
            x1 + " " + y1,
            x1 + " " + y2,
            x2 + " " + y1,
            x2 + " " + y2
        };

        for(String corn : corners){
            if(!dup_corner.contains(corn)) return false;
        }

        long total_area = (long) (x2 - x1)*(y2 - y1);

        return total_area == area;
    }
}