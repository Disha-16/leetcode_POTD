class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         auto atMostK = [](const vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int left = 0, res = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (count[nums[right]] == 0) k--;
            count[nums[right]]++;
            while (k < 0) {
                count[nums[left]]--;
                if (count[nums[left]] == 0) k++;
                left++;
            }
            res += right - left + 1;
        }
        return res;
    };
    
    return atMostK(nums, k) - atMostK(nums, k - 1);
        
    }
};
