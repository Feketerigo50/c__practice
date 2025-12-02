class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        int radius = 0;
        
        Arrays.sort(houses);
        Arrays.sort(heaters);

        for(int house : houses){
            int idx = Arrays.binarySearch(heaters, house);
            if(idx >= 0) continue;

            idx = -idx - 1;

            int distLeft = Integer.MAX_VALUE;
            int distRight = Integer.MAX_VALUE;

            if (idx < heaters.length) {
                distRight = heaters[idx] - house;
            }
            if (idx > 0) {
                distLeft = house - heaters[idx - 1];
            }

            radius = Math.max(radius, Math.min(distRight, distLeft));
        }

        return radius;
    }
}