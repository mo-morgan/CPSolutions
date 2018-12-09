class Solution {
    HashMap<Character, Integer> alphabet = new HashMap<>();
    public boolean isAlienSorted(String[] words, String order) {
        for (int i = 0; i < order.length(); i++) {
            alphabet.put(order.charAt(i), i);
        }
        
        for (int i = 0; i < words.length - 1; i++) {
            if (compare(words[i], words[i+1])) {
                continue;
            } else {
                return false;
            }
        }
        
        return true;
    }
    
    // returns true if first <= second
    public boolean compare(String first, String second) {
        int min = Math.min(first.length(), second.length());
        for (int i = 0; i < min; i++) {
            if (alphabet.get(first.charAt(i)) < alphabet.get(second.charAt(i))) {
                return true;
            } else if (alphabet.get(first.charAt(i)) > alphabet.get(second.charAt(i))) {
                return false;
            }
        }
        
        if (first.length() > second.length()) {
            return false;
        }
        
        return true;
    }
}