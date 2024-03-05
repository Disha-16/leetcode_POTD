class Solution {
public:
    int minimumLength(string s) {
           int n = s.length();

    // Start and end pointers
    int start = 0, end = n - 1;

    // Iterate while start is less than end
    while (start < end && s[start] == s[end]) {
        char currentChar = s[start];

        // Move the start pointer forward until a different character is found
        while (start <= end && s[start] == currentChar) {
            start++;
        }

        // Move the end pointer backward until a different character is found
        while (end >= start && s[end] == currentChar) {
            end--;
        }
    }

    // The remaining length of the string
    return end - start + 1;
        
    }
};
