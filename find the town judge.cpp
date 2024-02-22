class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScores(n + 1, 0); 

    // Calculate trust score by incrementing for every trust received
    // and decrementing for every trust given
    for (auto& relation : trust) {
        trustScores[relation[0]]--; // Person giving trust
        trustScores[relation[1]]++; // Person receiving trust
    }

    // The town judge should have a trust score of n - 1
    for (int i = 1; i <= n; ++i) {
        if (trustScores[i] == n - 1) {
            return i; // Found the town judge
        }
    }

    return -1; 
        
    }
};
