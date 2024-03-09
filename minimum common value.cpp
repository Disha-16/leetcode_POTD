class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
         int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            // Found the minimum common element
            return nums1[i];
        } else if (nums1[i] < nums2[j]) {
            // Move pointer in nums1 forward to find a potential match
            i++;
        } else {
            // Move pointer in nums2 forward to find a potential match
            j++;
        }
    }
    // If no common element is found, return -1
    return -1;
        
}
};
