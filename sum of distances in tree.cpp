class Solution {
public:
    vector<vector<int>> graph;
    vector<int> subtree_size;
    vector<long long> distance_sum;
    int n;

    // DFS1: Calculate subtree sizes and initial distance sums from the root node.
    void dfs1(int node, int parent) {
        subtree_size[node] = 1; // count itself
        distance_sum[node] = 0;
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue; // skip the edge back to parent
            dfs1(neighbor, node);
            subtree_size[node] += subtree_size[neighbor];
            distance_sum[node] += distance_sum[neighbor] + subtree_size[neighbor];
        }
    }

    // DFS2: Calculate the answer for all nodes using the re-rooting principle.
    void dfs2(int node, int parent) {
        // Apply the re-rooting formula
        if (parent != -1) {
            distance_sum[node] = distance_sum[parent] - subtree_size[node] + (n - subtree_size[node]);
        }
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            dfs2(neighbor, node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph.assign(n, vector<int>());
        subtree_size.assign(n, 0);
        distance_sum.assign(n, 0);

        // Build the graph from edges
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // First DFS to calculate subtree sizes and initial root-based distance sums
        dfs1(0, -1);
        // Second DFS to adjust distance sums based on the subtree results
        dfs2(0, -1);

        // Convert long long to int for result, assuming distances will fit in an int
        vector<int> result(distance_sum.begin(), distance_sum.end());
        return result;
        
    }
};
