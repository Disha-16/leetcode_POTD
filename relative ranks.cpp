class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
    std::vector<std::pair<int, int>> score_pairs;
    
    // Pair each score with its index
    for (int i = 0; i < n; ++i) {
        score_pairs.push_back({score[i], i});
    }
    
    // Sort scores in descending order
    std::sort(score_pairs.begin(), score_pairs.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                  return a.first > b.first;
              });
    
    // Prepare the result vector
    std::vector<std::string> result(n);
    
    // Assign ranks based on sorted scores
    for (int rank = 0; rank < n; ++rank) {
        int idx = score_pairs[rank].second; // original index of the score
        if (rank == 0) {
            result[idx] = "Gold Medal";
        } else if (rank == 1) {
            result[idx] = "Silver Medal";
        } else if (rank == 2) {
            result[idx] = "Bronze Medal";
        } else {
            result[idx] = std::to_string(rank + 1);
        }
    }
    
    return result;
        
    }
};
