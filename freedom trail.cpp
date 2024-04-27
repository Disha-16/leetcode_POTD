class Solution {
public:
    int findRotateSteps(string ring, string key) {
         int n = ring.size();
    int m = key.size();

    // dp[i][j] will hold the minimum steps needed to spell until key[i] with ring[j] at the 12:00 position
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

    // Precompute positions of each character in ring to avoid repeated scanning
    unordered_map<char, vector<int>> charPositions;
    for (int i = 0; i < n; ++i) {
        charPositions[ring[i]].push_back(i);
    }

    // Initialize the first key character calculations
    for (int pos : charPositions[key[0]]) {
        dp[0][pos] = min(pos, n - pos) + 1; // clockwise vs counterclockwise
    }

    // Fill the dp table
    for (int i = 1; i < m; ++i) {
        for (int pos : charPositions[key[i]]) {
            for (int prevPos : charPositions[key[i - 1]]) {
                int dist = abs(pos - prevPos); // distance between current and previous character positions
                int step = min(dist, n - dist) + 1; // minimum steps from prevPos to pos
                dp[i][pos] = min(dp[i][pos], dp[i - 1][prevPos] + step);
            }
        }
    }

    // Find the minimum steps to complete the spelling of the last character in key
    int minSteps = INT_MAX;
    for (int pos : charPositions[key[m - 1]]) {
        minSteps = min(minSteps, dp[m - 1][pos]);
    }

    return minSteps;
        
    }
};
