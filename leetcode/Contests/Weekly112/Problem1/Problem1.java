// Timeout on a few test cases

class Solution {
    Map<Integer, Integer> numMap = new HashMap<>();
    int after;
    
    public int minIncrementForUnique(int[] A) {
        int sum = 0;
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
            if (!numMap.containsKey(A[i])) {
                numMap.put(A[i], 1);
            } else {
                numMap.put(A[i], 1 + numMap.get(A[i]));
            }
        }
        int[] B = A;
        after = sum;
        for (int i = 0; i < A.length; i++) {
            if (numMap.get(B[i]) > 1) {
                numMap.put(B[i], numMap.get(B[i]) - 1);
                B[i]++;
                after++;
                int key = B[i];
                while (isNotUnique(key)) {
                    B[i]++;
                    key++;
                }
            }
        }
        
        int numIncrement = after - sum;
        
        return numIncrement;
    }
    
    public boolean isNotUnique(int key) {
        if (!numMap.containsKey(key)) {
            numMap.put(key, 1);
            return false;
        } else {
            after++;
            return true;
        }
    }

}