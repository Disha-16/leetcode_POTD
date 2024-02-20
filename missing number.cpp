class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
    // Calculate the expected sum of the first n natural numbers
    int total = n * (n + 1) / 2;
    // Calculate the sum of elements in the array
    int sum = 0;
    for(int num : nums) {
        sum += num;
    }
    // The difference is the missing number
    return total - sum;
        
    }
};
