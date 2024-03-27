class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // Since k is strictly less than, and all elements are positive.
    int count = 0;
    int product = 1;
    int left = 0;
    for (int right = 0; right < nums.size(); ++right) {
        product *= nums[right];
        // Shrink the window from the left if the product is equal or greater than k
        while (product >= k) {
            product /= nums[left++];
        }
        // For each position of right, the number of intervals ending with nums[right]
        // and having product less than k is (right - left + 1)
        count += right - left + 1;
    }
    return count;
        
    }
};
