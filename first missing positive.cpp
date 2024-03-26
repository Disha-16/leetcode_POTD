class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // While nums[i] is in the range [1, n] and nums[nums[i] - 1] != nums[i],
            // swap nums[i] with nums[nums[i] - 1]
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Find the first element which is not i + 1, meaning it's the first missing positive
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If we didn't return from the loop, it means all numbers from 1 to n are present
        return n + 1;
        
    }
};
