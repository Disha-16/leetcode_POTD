class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
    bool charFound = false;

    // Start from the end of the string
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            charFound = true;
            length++;
        } else if (charFound) {
            // Once we've found the last word and encounter a space, break the loop
            break;
        }
    }
    
    return length;
        
    }
};
