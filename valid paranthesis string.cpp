class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  // Minimum number of open parentheses
    int high = 0; // Maximum number of open parentheses
    for (char c : s) {
        if (c == '(') {
            low++;  // Must be an open parenthesis
            high++; // Could be an open parenthesis
        } else if (c == ')') {
            if (low > 0) low--; // Matched with an open parenthesis
            high--; // Must close a parenthesis
        } else { // c == '*'
            if (low > 0) low--; // Use * as ')'
            high++; // Use * as '('
        }
        if (high < 0) return false; // More closing parentheses than opening
    }
    return low == 0; 
        
    }
};
