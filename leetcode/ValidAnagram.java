class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> counter = new HashMap<>();
        int n = s.length();
        int m = t.length();
        for (int i = 0; i < n; i++) {
            char s_char = s.charAt(i);
            if (counter.get(s_char) == null) {
                counter.put(s_char, 1);
            } else {
                counter.put(s_char, counter.get(s_char) + 1);
            }
        }

        for (int i = 0; i < m; i++) {
            char t_char = t.charAt(i);
            if (counter.get(t_char) == null) {
                counter.put(t_char, -1);
            } else {
                counter.put(t_char, counter.get(t_char) - 1);
            }
        }
        for (Integer value : counter.values()) {
            if (value != 0) return false;
        }
        return true;
    }

    public boolean isAnagramFast(String s, String t) {
        int[] a = new int[26];
        char[] c1 = s.toCharArray();
        char[] c2 = t.toCharArray();
        for(int i = 0;i<c1.length;i++){
            int f = c1[i];
            a[f - 'a'] += 1;
        }
        for(int i = 0;i<c2.length;i++){
            int l = c2[i];
            a[l - 'a'] -= 1;
        }
        for(int i = 0;i<26;i++){
            if(a[i] != 0){
                return false;
            }
        }
        return true;
    }
}