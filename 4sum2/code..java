class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Map<Integer, Integer> counter = new HashMap<>();

        for(int num1 : nums1){
            for(int num2 : nums2){
                counter.put(num1 + num2, counter.getOrDefault(num1 + num2, 0) + 1);
            }
        }

        int result = 0;
        for(int num3 : nums3){
            for(int num4 : nums4){
                int sum = -(num3 + num4);
                result += counter.getOrDefault(sum, 0);
            }
        }

        return result;
    }
}