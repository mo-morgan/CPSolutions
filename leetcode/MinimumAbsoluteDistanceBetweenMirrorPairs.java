class Solution {
    public int minMirrorPairDistance(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int minimum = Integer.MAX_VALUE;
        // the idea is to store the reversed integer and it's coordinates in the hashmap
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            if (map.containsKey(num)) {
                minimum = Math.min(minimum, Math.abs(map.get(num) - i));
            }
            map.put(reverse(nums[i]), i);
        }

        if (minimum == Integer.MAX_VALUE) return -1;
        return minimum;
    }

    private int reverse(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        return rev; // reverse(9100) = 19, reverse(8048) = 8408
    }
}