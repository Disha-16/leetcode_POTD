class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         unordered_map<int, int> sumIndexMap;
    int sum = 0; // Cumulative sum of the array, treating 0 as -1 and 1 as 1
    int maxLength = 0;
    
    // Adding a base case for the cumulative sum 0 at index -1 to handle cases
    // where the subarray starts from the beginning
    sumIndexMap[0] = -1;

    for (int i = 0; i < nums.size(); ++i) {
        // If the current element is 0, subtract 1 from sum. Else, add 1.
        sum += nums[i] == 0 ? -1 : 1;
        
        // If this cumulative sum has been seen before, calculate the length of the subarray
        if (sumIndexMap.find(sum) != sumIndexMap.end()) {
            maxLength = max(maxLength, i - sumIndexMap[sum]);
        } else {
            // If this is the first time we see this sum, store the index
            sumIndexMap[sum] = i;
        }
    }

    return maxLength;
        
    }
};
