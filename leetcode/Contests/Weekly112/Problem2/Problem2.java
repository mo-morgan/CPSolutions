class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        boolean pos = true;
        Stack st = new Stack();
        int topop = 0;
        for (int i = 0; i < pushed.length; i++) {
            st.push(pushed[i]);
            for (int j = 0; j < pushed.length; j++) {
                if (!st.empty()) {
                    if (st.peek().equals(popped[topop])) {
                        st.pop();
                        topop++;
                    } else {
                        break;
                    }
                }
            }
        }
        if (!st.empty()) {
            if (!st.peek().equals(popped[topop])) {
                return false;
            }
        }
        
        return true;
    }
}