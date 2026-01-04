class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        HashMap<Integer, Integer> countMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int k = nums1[i];
            if (countMap.get(k) != null) {
                countMap.put(k, countMap.get(k) + 1);
            } else {
                countMap.put(k, 1);
            }
        }
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int k = nums2[i];
            if (countMap.get(k) != null && countMap.get(k) > 0) {
                result.add(k);
                countMap.put(k, countMap.get(k) - 1);
            }
        }
        int[] ret = result.stream()
                    .mapToInt(Integer::intValue)
                    .toArray();
        return ret;
    }
}