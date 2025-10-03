class Solution {
    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        int[][] ascend = new int[n][2];
        for(int i = 0; i < n; i++){
            ascend[i][0] = intervals[i][0];
            ascend[i][1] = i;
        }

        Arrays.sort(ascend, (a, b) -> a[0] - b[0]);

        int[] result = new int[n];
        Arrays.fill(result, -1);

        for(int i = 0; i < n; i++){
            int last = intervals[i][1];
            int left = 0;
            int right = n-1;
            int index = -1;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(ascend[mid][0] >= last){
                    index = ascend[mid][1];
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
            if(index != -1){
                result[i] = index;
            }
        }

        return result;
    }
}