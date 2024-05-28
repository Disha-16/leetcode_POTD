class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
          int maxLength = 0;
        int[] costArray = new int[s.length()];

        // Calculate the cost array
        for (int i = 0; i < s.length(); i++) {
            costArray[i] = Math.abs(s.charAt(i) - t.charAt(i));
        }

        // Sliding window approach
        int windowStart = 0;
        int windowEnd = 0;
        int currentCost = 0;

        while (windowEnd < s.length()) {
            currentCost += costArray[windowEnd];

            // If the cost exceeds maxCost, shrink the window
            while (currentCost > maxCost) {
                currentCost -= costArray[windowStart];
                windowStart++;
            }

            // Update maxLength
            maxLength = Math.max(maxLength, windowEnd - windowStart + 1);

            // Move window end
            windowEnd++;
        }

        return maxLength;
    }
}
