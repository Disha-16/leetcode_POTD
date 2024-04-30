class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long count = 0;
    int mask = 0;
    unordered_map<int, int> mask_count;
    mask_count[0] = 1;  // One way to have a zero mask before any character is processed.

    for (char ch : word) {
        int index = ch - 'a';
        mask ^= (1 << index);  // Toggle the bit corresponding to the character.
        
        count += mask_count[mask];  // Add all substrings that continue to be wonderful.

        // Check all masks that differ by one bit
        for (int i = 0; i < 10; i++) {
            int toggled_mask = mask ^ (1 << i);
            count += mask_count[toggled_mask];
        }

        // Update the count of this mask in the map
        mask_count[mask]++;
    }

    return count;
        
    }
};
