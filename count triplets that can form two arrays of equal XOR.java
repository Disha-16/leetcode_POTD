class Solution {
    public int countTriplets(int[] arr) {
         int n = arr.length;
        int count = 0;

        // Traverse through all possible pairs of indices (i, j)
        for (int i = 0; i < n - 1; i++) {
            int xor = arr[i];
            for (int j = i + 1; j < n; j++) {
                // Calculate xor of elements from i to j
                xor ^= arr[j];

                // If xor is 0, then elements from i to j have same xor
                if (xor == 0) {
                    // Number of elements between i and j can form a triplet
                    count += (j - i);
                }
            }
        }

        return count;
    }
}
