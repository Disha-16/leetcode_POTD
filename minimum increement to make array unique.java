class Solution {
    public int minIncrementForUnique(int[] nums) {
          Arrays.sort(nums);
        
        // Initialize the number of moves
        int moves = 0;
        
        // Iterate through the sorted array and ensure uniqueness
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] <= nums[i - 1]) {
                // If the current element is not greater than the previous, increment it
                int increment = nums[i - 1] - nums[i] + 1;
                nums[i] += increment;
                moves += increment;
            }
        }
        
        return moves;
    }
}
