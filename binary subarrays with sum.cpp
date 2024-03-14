class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
    int sum = 0;
    unordered_map<int, int> prefixSums;
    prefixSums[0] = 1; // To handle the case when a subarray starts from index 0

    for (int num : nums) {
        sum += num; // Current prefix sum
        if (prefixSums.find(sum - goal) != prefixSums.end()) {
            count += prefixSums[sum - goal];
        }
        prefixSums[sum]++;
    }

    return count;
        
  }  
};
