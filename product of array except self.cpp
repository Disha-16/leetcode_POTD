class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    vector<int> answer(n);

    // Calculate prefix products.
    vector<int> prefix(n, 1);
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // Calculate suffix products and the final result.
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] = prefix[i] * suffix;
        suffix *= nums[i];
    }

    return answer;
        
    }
};
