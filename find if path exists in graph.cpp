class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         if (source == destination) return true;

    // Build the adjacency list
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS initialization
    queue<int> q;
    vector<bool> visited(n, false);

    // Start BFS from the source node
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Explore each adjacent vertex
        for (int neighbor : adj[current]) {
            if (neighbor == destination) {
                return true;  // Found the destination
            }
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return false;
        
    }
};
