class Solution {
public:
    string removeKdigits(string num, int k) {
         string result = ""; // Use this string as a stack.
    
    for(char digit : num) {
        // While stack is not empty, and the last digit in the stack is greater than
        // the current digit, and we still have digits to remove (k > 0),
        // remove the last digit from the stack.
        while(!result.empty() && result.back() > digit && k > 0) {
            result.pop_back();
            k--;
        }
        
        // If the current digit is not '0', or the stack is not empty (to avoid leading zeros),
        // push the current digit to the stack.
        if(!result.empty() || digit != '0') {
            result.push_back(digit);
        }
    }
    
    // If we still have digits to remove, remove them from the end.
    while(k-- > 0 && !result.empty()) {
        result.pop_back();
    }
    
    // If the result is empty, return "0".
    return result.empty() ? "0" : result;
        
    }
};
