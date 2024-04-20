class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
    int n = land[0].size();
    vector<vector<int>> groups;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // Find the top-left corner of a new group.
            if (land[i][j] == 1 && (i == 0 || land[i - 1][j] == 0) && (j == 0 || land[i][j - 1] == 0)) {
                int r2 = i;
                int c2 = j;
                
                // Expand the group to find its full extent in terms of rows.
                while (r2 + 1 < m && land[r2 + 1][j] == 1) {
                    ++r2;
                }
                
                // Expand the group to find its full extent in terms of columns.
                while (c2 + 1 < n && land[i][c2 + 1] == 1) {
                    ++c2;
                }
                
                // Check for the furthest extent in the column for all rows in the current group.
                for (int k = i; k <= r2; ++k) {
                    while (c2 + 1 < n && land[k][c2 + 1] == 1) {
                        ++c2;
                    }
                }
                
                // Add the coordinates of the rectangle to the result list.
                groups.push_back({i, j, r2, c2});
            }
        }
    }

    return groups;
        
    }
};
