// Wrong answer: needed to find number of columns to keep instead of to delete by searching if the current sequence is in order

class Solution {
    public int minDeletionSize(String[] A) {
        int max = 0;
        int [] indexesDeleted = new int[A[0].length()];
        for (int i = 0; i < A.length; i++) {
            String s = A[i];
            int numToDelete = 0;
            int duplicate = 0;
            boolean dup = false;
            int [] k = new int[s.length()];
            char [] j = s.toCharArray();
            for (int n = 0 ; n < j.length; n++) {
                int g = Character.getNumericValue(j[n]);
                k[n] = g;
            }
            numToDelete = minimumNumberOfDeletions(k, k.length);
            
            if (numToDelete > max) {
                max = numToDelete;
            }
        }
        
        return max;
    }
    
    static int minimumNumberOfDeletions(int arr[],  
                                        int n) { 
        // Find longest  
        // increasing subsequence 
        int len = lis(arr, n); 
      
        // After removing elements  
        // other than the lis, we get 
        // sorted sequence. 
        return (n - len); 
    } 
    
    static int lis( int arr[], int n ) 
    { 
        int result = 0; 
        int[] lis = new int[n]; 
      
        /* Initialize LIS values  
        for all indexes */
        for (int i = 0; i < n; i++ ) 
            lis[i] = 1; 
      
        /* Compute optimized LIS  
           values in bottom up manner */
        for (int i = 1; i < n; i++ ) 
            for (int j = 0; j < i; j++ ) 
                if ( arr[i] > arr[j] && 
                    lis[i] < lis[j] + 1) 
                    lis[i] = lis[j] + 1; 
      
        /* Pick resultimum of 
        all LIS values */
        for (int i = 0; i < n; i++ ) 
            if (result < lis[i]) 
                result = lis[i]; 
      
        return result; 
    } 
}