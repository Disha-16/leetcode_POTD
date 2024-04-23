class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};  // Special case: only one node in the tree
    
    // Adjacency list and degree of each node
    std::vector<std::vector<int>> adj(n);
    std::vector<int> degree(n, 0);
    
    // Build graph
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }
    
    // Initialize leaves
    std::queue<int> leaves;
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 1) {
            leaves.push(i);
        }
    }
    
    // Process leaves layer by layer
    int remainingNodes = n;
    while (remainingNodes > 2) {
        int leavesSize = leaves.size();
        remainingNodes -= leavesSize;
        for (int i = 0; i < leavesSize; ++i) {
            int leaf = leaves.front();
            leaves.pop();
            for (int neighbor : adj[leaf]) {
                if (--degree[neighbor] == 1) {
                    leaves.push(neighbor);
                }
            }
        }
    }
    
    // Collect remaining nodes
    std::vector<int> result;
    while (!leaves.empty()) {
        result.push_back(leaves.front());
        leaves.pop();
    }
    
    return result;
    }
};
