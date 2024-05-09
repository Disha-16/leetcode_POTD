class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
          sort(happiness.rbegin(), happiness.rend());
    
    int n = happiness.size();
    long long maxHappiness = 0;
    long long cumulativeDecrease = 0;

    for (int i = 0; i < k; ++i) {
        // Add the current highest happiness minus the cumulative decrease
        // Happines values should not go below zero due to the decrease
        if (happiness[i] - cumulativeDecrease > 0) {
            maxHappiness += happiness[i] - cumulativeDecrease;
        }
        cumulativeDecrease++;
    }
    
    return maxHappiness;
        
    }
};
