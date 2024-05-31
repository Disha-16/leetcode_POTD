class Solution {
    public int[] singleNumber(int[] nums) {
        int xorResult = 0;
        for (int num : nums) {
            xorResult ^= num;
        }
        
        // Step 2: Find the rightmost set bit in xorResult
        int rightmostSetBit = 1;
        while ((rightmostSetBit & xorResult) == 0) {
            rightmostSetBit <<= 1;
        }
        
        // Step 3: Divide the nums array into two groups based on the rightmost set bit
        int group1 = 0;
        int group2 = 0;
        for (int num : nums) {
            if ((num & rightmostSetBit) == 0) {
                group1 ^= num;
            } else {
                group2 ^= num;
            }
        }
        
        // Return the two elements that appear only once
        return new int[]{group1, group2};    
    }
}
