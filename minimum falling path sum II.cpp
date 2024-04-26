class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
         int n = grid.size();
    if (n == 1) return grid[0][0];
    
    // Initialize dp table
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) {
        dp[0][j] = grid[0][j];
    }

    // Fill dp table
    for (int i = 1; i < n; ++i) {
        // First find the minimum and second minimum in the previous row
        int firstMin = INT_MAX, secondMin = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (dp[i-1][j] <= firstMin) {
                secondMin = firstMin;
                firstMin = dp[i-1][j];
            } else if (dp[i-1][j] < secondMin) {
                secondMin = dp[i-1][j];
            }
        }
        
        for (int j = 0; j < n; ++j) {
            // If current element in the previous row was the minimum, use second minimum
            if (dp[i-1][j] == firstMin) {
                dp[i][j] = grid[i][j] + secondMin;
            } else {
                dp[i][j] = grid[i][j] + firstMin;
            }
        }
    }
    
    // Get the minimum value from the last row of dp
    return *min_element(dp[n-1].begin(), dp[n-1].end());
        
    }
};
