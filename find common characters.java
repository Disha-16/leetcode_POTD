class Solution {
    public List<String> commonChars(String[] words) {
          List<String> result = new ArrayList<>();
        
        // Count characters in the first word
        Map<Character, Integer> charCount = new HashMap<>();
        for (char c : words[0].toCharArray()) {
            charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        }
        
        // For each subsequent word, update the character count
        for (int i = 1; i < words.length; i++) {
            Map<Character, Integer> temp = new HashMap<>();
            for (char c : words[i].toCharArray()) {
                if (charCount.containsKey(c) && charCount.get(c) > 0) {
                    temp.put(c, temp.getOrDefault(c, 0) + 1);
                    charCount.put(c, charCount.get(c) - 1);
                }
            }
            charCount = temp;
        }
        
        // Add characters to the result list based on their count
        for (Map.Entry<Character, Integer> entry : charCount.entrySet()) {
            for (int i = 0; i < entry.getValue(); i++) {
                result.add(String.valueOf(entry.getKey()));
            }
        }
        
        return result;
    }
}
