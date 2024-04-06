class Solution {
public:
    string minRemoveToMakeValid(string s) {
         stack<int> parentheses; // Stack to keep track of '(' positions
    vector<bool> isValid(s.size(), true); // Mark each character as valid initially

    // First pass to mark invalid ')' and track '('
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            // Push the index of '(' onto the stack
            parentheses.push(i);
        } else if (s[i] == ')') {
            if (parentheses.empty()) {
                // If there's no matching '(', mark this ')' as invalid
                isValid[i] = false;
            } else {
                // Found a matching pair, pop the stack
                parentheses.pop();
            }
        }
        // Ignore lowercase English letters as they don't affect validity
    }

    // Mark remaining '(' in the stack as invalid
    while (!parentheses.empty()) {
        isValid[parentheses.top()] = false;
        parentheses.pop();
    }

    // Second pass to build the result string
    string result;
    for (int i = 0; i < s.size(); ++i) {
        if (isValid[i]) {
            result += s[i];
        }
    }

    return result;
        
    }
};
