class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        boolean exists = false;
        char min = '{';
        int n = letters.length;
        for (int i = 0; i < n; i++) {
            if (letters[i] > target && letters[i] < min) {
                min = letters[i];
                exists = true;
            }
        }
        return exists ? min : letters[0];
    }
}