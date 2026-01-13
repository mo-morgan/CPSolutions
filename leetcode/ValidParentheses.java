class Solution {
    public boolean isValid(String s) {
        String validTypes = "([{)]}";
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            // if curr is open brace type, we keep pushing
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                char last = stack.peek();
                if (c == ')' && last != '(') {
                    return false;
                }
                if (c == ']' && last != '[') {
                    return false;
                }
                if (c == '}' && last != '{') {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.isEmpty();
    }
}