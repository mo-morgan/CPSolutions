// My solution did not cover when you have something like [-1,1,-2,2,-2,2,-4,4]
//   the above input should output true but since my solution only checks for if /2 == curr and *2 == curr
//							it overlooked the fact that you can have multiple pairs using the same number

// instead, I needed to remove the pairs from my map once I have used them and only return false
// 									if I ran out of working pairs.

class Solution {
    HashMap<Integer, Integer> sol = new HashMap<>();
    public boolean canReorderDoubled(int[] A) {
        boolean canBeReordered = false;
        for (int i = 0; i < A.length; i++) {
            if (sol.containsKey(A[i])) {
                sol.put(A[i], sol.get(A[i]) + 1);
            } else {
                sol.put(A[i], 1);   
            }
        }
        
        Iterator it = sol.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry pair = (Map.Entry)it.next();
            // int key = pair.getKey().intValue();
            // int value = pair.getValue().intValue();
            Integer i = new Integer(pair.getKey().toString());
            Integer j = new Integer(pair.getValue().toString());
            
            int key;
            int value;
            
            
            key = Integer.parseInt(i.toString());
            
            value = Integer.parseInt(j.toString());
            
            if (sol.containsKey(key * 2)) {
                if (sol.get(key * 2).equals(value)) {
                    continue;
                }
            }
            
            if (key % 2 == 1) {
                return false;
            }
            
            if (sol.containsKey(key / 2)) {
                if (sol.get(key / 2).equals(value)) {
                    continue;
                }
            }
            
            return false;
        }
        
        return true;
    }
}