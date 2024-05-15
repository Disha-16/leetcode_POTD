class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
         int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    // Initialize the queue with all thieves' locations
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] == 1) {
                q.push({r, c});
                dist[r][c] = 0; // Distance to itself is zero
            }
        }
    }

    // Directions for the movement (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // BFS to calculate the minimum distance of each cell from any thief
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto& dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] > dist[r][c] + 1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    // Now find the path from (0, 0) to (n-1, n-1) that maximizes the minimum distance to any thief
    vector<vector<int>> maxDist(n, vector<int>(n, -1));
    queue<pair<int, int>> pq;
    pq.push({0, 0});
    maxDist[0][0] = dist[0][0]; // Start with the safeness factor at the starting point

    while (!pq.empty()) {
        auto [r, c] = pq.front();
        pq.pop();

        for (auto& dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                // We want the smallest of the current path safeness factors to carry forward
                int newDist = min(maxDist[r][c], dist[nr][nc]);
                if (newDist > maxDist[nr][nc]) {
                    maxDist[nr][nc] = newDist;
                    pq.push({nr, nc});
                }
            }
        }
    }

    return maxDist[n-1][n-1];
    }
};
