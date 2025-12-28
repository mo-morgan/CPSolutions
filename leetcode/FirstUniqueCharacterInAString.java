class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> counter = new HashMap<>();
        boolean[] uniqueCharacters = new boolean[26];
        boolean hasAppeared = true;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (uniqueCharacters[c - 'a'] == hasAppeared) {
                counter.put(c, -1);
            } else {
                counter.put(c, i);
                uniqueCharacters[c - 'a'] = hasAppeared;
            }
        }
        int minIndicie = Integer.MAX_VALUE;
        for (Character c : counter.keySet()) {
            int k = counter.get(c);
            if (k != -1) {
                minIndicie = Math.min(minIndicie, k);
            }
        }
        if (minIndicie == Integer.MAX_VALUE) {
            minIndicie = -1;
        }
        return minIndicie;
    }
}