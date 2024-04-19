class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Check boundary conditions
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }

        // Check if the current cell is water or visited
        if (grid[i][j] == '0') {
            return;
        }

        // Mark the current cell as visited by setting it to '0'
        grid[i][j] = '0';

        // Recursively visit all connecting cells (vertical and horizontal)
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Start a new DFS if we find unvisited land
                if (grid[i][j] == '1') {
                    ++num_islands;
                    dfs(grid, i, j);
                }
            }
        }

        return num_islands;
        
    }
};
