class Solution {
    public int numSteps(String s) {
           int steps = 0;
        int carry = 0;
        
        // Start from the second last digit of the binary string
        for (int i = s.length() - 1; i > 0; i--) {
            int digit = s.charAt(i) - '0' + carry;
            
            if (digit == 1) {
                steps += 2; // If the digit is odd, add 1 and divide by 2
                carry = 1;
            } else {
                steps++; // If the digit is even, just divide by 2
            }
        }
        
        // If there is a carry at the end, add 1 to the steps
        steps += carry;
        
        return steps;
    }
}
