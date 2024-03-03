class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int countZero = 0, countOne = 0;

    // Count the number of '0's and '1's in the string
    for (char c : s) {
        if (c == '0') countZero++;
        else if (c == '1') countOne++;
    }

    // If there's only one '1', it must be placed at the end, resulting in "001" for the example
    // This handles the case where the maximum odd binary number is simply "1"
    if (countOne == 1) return string(countZero, '0') + "1";

    // Place one '1' at the end to ensure the number is odd
    // Then, place all remaining '1's at the beginning and all '0's in the middle
    return string(countOne - 1, '1') + string(countZero, '0') + "1";
    }
};
