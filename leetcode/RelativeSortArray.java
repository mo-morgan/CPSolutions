// Original solution but creates unnecessary arrays in recursive calls that uses additional memory
class Solution1 {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        HashMap<Integer, Integer> comparatorMap = new HashMap<>();

        // setup the comparator array
        for (int i = 0; i < arr2.length; i++) {
            // because all the elements of arr2 are distinct
            comparatorMap.put(arr2[i], i);
        }

        int[] ans = mergeSort(arr1, comparatorMap);
        return ans;
    }

    private int[] mergeSort(int[] arr, HashMap<Integer, Integer> map) {
        int k = arr.length;
        if (k < 2) {
            return arr;
        }

        int[] arrLeft = mergeSort(Arrays.copyOfRange(arr, 0, k/2), map);
        int[] arrRight = mergeSort(Arrays.copyOfRange(arr, k/2, k), map);

        int n = arrLeft.length;
        int m = arrRight.length; 
        int[] ret = new int[n + m];
        
        int pointerL = 0;
        int pointerR = 0;
        for (int i = 0; i < ret.length; i++) {
            if (pointerL >= n) {
                ret[i] = arrRight[pointerR++];
                continue;
            } else if (pointerR >= m) {
                ret[i] = arrLeft[pointerL++];
                continue;
            } 
            int leftComp = map.getOrDefault(arrLeft[pointerL], Integer.MAX_VALUE);
            int rightComp = map.getOrDefault(arrRight[pointerR], Integer.MAX_VALUE);

            if (leftComp == Integer.MAX_VALUE && rightComp == Integer.MAX_VALUE) {
                // max result
                if (arrLeft[pointerL] < arrRight[pointerR]) {
                    ret[i] = arrLeft[pointerL++];
                } else {
                    ret[i] = arrRight[pointerR++];
                }
            } else if (rightComp < leftComp) {
                ret[i] = arrRight[pointerR++];
            } else {
                ret[i] = arrLeft[pointerL++];
            }
        }

        return ret;
    }
}

// New solution which uses textbook mergesort algorithm
class Solution2 {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map<Integer, Integer> order = new HashMap<>();
        for (int i = 0; i < arr2.length; i++) {
            order.put(arr2[i], i); // arr2 elements are distinct
        }

        int[] temp = new int[arr1.length];
        sort(arr1, 0, arr1.length - 1, temp, order);
        return arr1;
    }

    private void sort(int[] arr, int left, int right, int[] temp, Map<Integer, Integer> order) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        sort(arr, left, mid, temp, order);
        sort(arr, mid + 1, right, temp, order);

        merge(arr, left, mid, right, temp, order);
    }

    private void merge(int[] arr, int left, int mid, int right, int[] temp, Map<Integer, Integer> order) {
        int i = left;      // pointer in left half
        int j = mid + 1;   // pointer in right half
        int k = left;      // pointer in temp (same range)

        while (i <= mid && j <= right) {
            if (comesBefore(arr[i], arr[j], order)) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        // copy merged range back
        for (int t = left; t <= right; t++) {
            arr[t] = temp[t];
        }
    }

    // Returns true if a should be placed before b
    private boolean comesBefore(int a, int b, Map<Integer, Integer> order) {
        int aRank = order.getOrDefault(a, Integer.MAX_VALUE);
        int bRank = order.getOrDefault(b, Integer.MAX_VALUE);

        // If both are not in arr2, sort numerically ascending
        if (aRank == Integer.MAX_VALUE && bRank == Integer.MAX_VALUE) {
            return a < b;
        }

        // Otherwise, smaller rank comes first (ties: stable -> keep left first)
        return aRank <= bRank;
    }
}