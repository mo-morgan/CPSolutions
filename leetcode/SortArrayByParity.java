class Solution {
    public int[] sortArrayByParity(int[] nums) {
        List<Integer> ret = new LinkedList<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num % 2 == 0) {
                ret.addFirst(num);
            } else {
                ret.add(num);
            }
        }
        int[] ans = ret.stream()
                        .mapToInt(Integer::intValue).toArray();
        return ans;
    }
}