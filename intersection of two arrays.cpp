class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> setNums1(nums1.begin(), nums1.end());
        set<int> setNums2(nums2.begin(), nums2.end());

        vector<int> intersection;
    
    // Iterate through the smaller set
    if (setNums1.size() < setNums2.size()) {
        for (int num : setNums1) {
            // Check if the element is present in both sets
            if (setNums2.find(num) != setNums2.end()) {
                intersection.push_back(num);
            }
        }
    } else {
        for (int num : setNums2) {
            if (setNums1.find(num) != setNums1.end()) {
                intersection.push_back(num);
            }
        }
    }
    
    return intersection;
        
    }
};
