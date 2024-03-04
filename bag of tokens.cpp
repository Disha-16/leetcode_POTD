class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       sort(tokens.begin(), tokens.end()); // Sort tokens in ascending order
        int score = 0;
        int maxScore = 0;
        int i = 0; // Start pointer
        int j = tokens.size() - 1; // End pointer

        while (i <= j) {
            if (power >= tokens[i]) {
                // Play the token face-up
                power -= tokens[i++];
                maxScore = max(maxScore, ++score);
            } else if (score > 0) {
                // Play the token face-down if score is available to spend
                power += tokens[j--];
                --score;
            } else {
                // Not enough power to play face-up and no score to play face-down
                break;
            }
        }

        return maxScore;
        
    }
};
