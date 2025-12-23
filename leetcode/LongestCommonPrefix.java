class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        if (n == 0) {
            return "";
        }
        Arrays.sort(strs, (a, b)->Integer.compare(a.length(), b.length()));
        int m = strs[0].length();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            boolean isAllSame = true;
            char prev = 0;
            for (int j = 0; j < n; j++) {
                char c = strs[j].charAt(i);
                if (prev != 0 && prev != c) {
                    isAllSame = false;
                }
                prev = c;
            }
            if (!isAllSame) {
                break;
            }
            sb.append(prev);
        }
        return sb.toString();
    }
}