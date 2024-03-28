class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // To store the frequency of elements in the current window
    int left = 0; // Start of the window
    int maxLength = 0; // The maximum length of the good subarray found so far

    for (int right = 0; right < nums.size(); ++right) {
        // Increment the frequency of the current element
        freq[nums[right]]++;

        // If the frequency of any element exceeds k, shrink the window from the left
        while (freq[nums[right]] > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]); // Remove the element from the map if its frequency is 0
            }
            left++; // Shrink the window
        }

        // Update the maximum length found so far
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
        
    }
};
