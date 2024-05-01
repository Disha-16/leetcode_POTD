class Solution {
public:
    string reversePrefix(string word, char ch) {
         size_t pos = word.find(ch);
    
    // Check if the character `ch` was found.
    if (pos != std::string::npos) {
        // Reverse the substring from the beginning up to and including `pos`.
        std::reverse(word.begin(), word.begin() + pos + 1);
    }
    
    // Return the modified or unmodified string.
    return word;
        
    }
};
