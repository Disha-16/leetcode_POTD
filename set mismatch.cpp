class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2, 0);
    std::unordered_set<int> numSet;
    int n = nums.size();

    // Calculate the sum of the original sequence (1 to n)
    int expectedSum = n * (n + 1) / 2;

    // Calculate the actual sum and identify the duplicate
    int actualSum = 0, duplicate = 0;
    for (int num : nums) {
        actualSum += num;
        if (numSet.find(num) != numSet.end()) {
            duplicate = num;
        }
        numSet.insert(num);
    }

    // Calculate the missing number
    int missing = expectedSum - (actualSum - duplicate);

    result[0] = duplicate;
    result[1] = missing;

    return result;
}
};

