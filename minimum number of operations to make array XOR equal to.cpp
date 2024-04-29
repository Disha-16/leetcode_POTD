class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
         int current_xor = 0;
    for (int num : nums) {
        current_xor ^= num;
    }
    
    int xor_needed = current_xor ^ k;
    int flip_count = 0;
    
    // Count the number of bits set in xor_needed
    while (xor_needed > 0) {
        flip_count += xor_needed & 1;
        xor_needed >>= 1;
    }
    
    return flip_count;
        
    }
};
