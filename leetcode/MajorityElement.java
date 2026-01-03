class Solution {
    public int majorityElementInPlace(int[] nums) {
        int res = 0;
        int majority = 0;
        for (int i = 0; i < nums.length; i++) {
            int k = nums[i];
            if (majority == 0) {
                res = nums[i];
            }

            if (res == k) majority++;
            else majority--;
        }
        return res;
    }

    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.get(nums[i]) == null) {
                map.put(nums[i], 1);
            } else {
                map.put(nums[i], map.get(nums[i]) + 1);
            }
        }
        int frequency = 0;
        int ans = -1;
        for (int key : map.keySet()) {
            int value = map.get(key);
            if (value > frequency) {
                frequency = value;
                ans = key;
            }
        }

        return ans;
    }
}