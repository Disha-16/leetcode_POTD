class Solution {
    public int longestPalindrome(String s) {
         HashMap<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        int length = 0;
        boolean hasOddFrequency = false;

        // Iterate through the frequency map
        for (int count : frequencyMap.values()) {
            // Add even occurrences of characters to the length
            length += count / 2 * 2;
            // If there is an odd occurrence, mark it
            if (count % 2 != 0) {
                hasOddFrequency = true;
            }
        }

        // If there was any character with odd occurrence, add 1 to the length
        if (hasOddFrequency) {
            length++;
        }

        return length;
    }
}
