class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
         int result = 0;
        std::vector<int> subset;
        backtrack(nums, 0, subset, result);
        return result;
    }
    
    void backtrack(std::vector<int>& nums, int index, std::vector<int>& subset, int& result) {
        result += xorSum(subset);
        for (int i = index; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }
    
    int xorSum(std::vector<int>& subset) {
        int xorTotal = 0;
        for (int num : subset) {
            xorTotal ^= num;
        }
        return xorTotal;
    }
};
