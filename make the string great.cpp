class Solution {
public:
    string makeGood(string s) {
         stack<char> charStack;

    for (char& c : s) {
        if (!charStack.empty()) {
            char top = charStack.top();
            // Check if current character and the top of the stack are a bad pair
            if (abs(top - c) == 32) {
                charStack.pop(); // Remove the top element as it forms a bad pair
                continue;
            }
        }
        charStack.push(c); // Push current character onto the stack
    }

    // Constructing the "good" string from the stack
    string goodStr = "";
    while (!charStack.empty()) {
        goodStr = charStack.top() + goodStr;
        charStack.pop();
    }

    return goodStr;
}
};
     
