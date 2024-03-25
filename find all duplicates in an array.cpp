class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
    for (int i = 0; i < nums.size(); ++i) {
        int index = std::abs(nums[i]) - 1; // Convert value to index
        if (nums[index] < 0) {
            // If the value at the index is already negative, this is a duplicate
            duplicates.push_back(index + 1); // Adjusting back to the value
        } else {
            // Mark the value at the index as seen by negating it
            nums[index] = -nums[index];
        }
    }
    return duplicates;
        
    }
};
