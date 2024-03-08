class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
         unordered_map<int, int> freqMap;
    
    // Count the frequency of each element
    for (int num : nums) {
        freqMap[num]++;
    }
    
    int maxFreq = 0;
    // Find the maximum frequency
    for (auto& pair : freqMap) {
        maxFreq = max(maxFreq, pair.second);
    }
    
    int totalCount = 0;
    // Count the total number of elements with the maximum frequency
    for (auto& pair : freqMap) {
        if (pair.second == maxFreq) {
            totalCount += maxFreq;
        }
    }
    
    return totalCount;
        
    }
};
