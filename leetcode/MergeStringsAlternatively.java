class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder ans = new StringBuilder("");
        int n = word1.length();
        int m = word2.length();
        for (int i = 0; i < Math.min(n, m); i++) {
            ans.append(word1.charAt(i));
            ans.append(word2.charAt(i));
        }
        if (n < m) {
            ans.append(word2.substring(n));
        } else {
            ans.append(word1.substring(m));
        }

        return ans.toString();
    }
}