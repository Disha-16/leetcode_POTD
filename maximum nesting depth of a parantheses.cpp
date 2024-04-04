class Solution {
public:
    int maxDepth(string s) {
         int currentDepth = 0, maxDepth = 0;
    for (char c : s) {
        if (c == '(') {
            currentDepth++; // Increase depth for '('
            maxDepth = max(maxDepth, currentDepth); // Update maxDepth if needed
        } else if (c == ')') {
            currentDepth--; // Decrease depth for ')'
        }
    }
    return maxDepth;
        
    }
};
