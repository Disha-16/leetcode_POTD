class Solution {
public:
    int longestIdealString(string s, int k) {
         vector<int> dp(26, 0); // dp array for 26 letters
    int n = s.length();
    int max_length = 0;
    
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a'; // converting character to its integer representation
        int max_for_c = 0;
        
        // Check all valid previous characters within the range determined by k
        for (int j = max(0, c - k); j <= min(25, c + k); ++j) {
            max_for_c = max(max_for_c, dp[j]);
        }
        
        dp[c] = max_for_c + 1; // Update the dp value for this character
        max_length = max(max_length, dp[c]); // Update the maximum length found
    }
    
    return max_length;
        
    }
};
