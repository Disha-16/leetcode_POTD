class Solution {
    public int scoreOfString(String s) {
          int score = 0;
        for (int i = 1; i < s.length(); i++) {
            // Calculate the absolute difference between ASCII values of adjacent characters
            score += Math.abs(s.charAt(i) - s.charAt(i - 1));
        }
        return score;
    }
}
