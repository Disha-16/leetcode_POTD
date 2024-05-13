class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
         int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns
        int result = 0;

        // Step through each column, determine the best toggle strategy
        for (int j = 0; j < n; j++) {
            int countOnes = 0;

            // Check how many ones are in the column
            for (int i = 0; i < m; i++) {
                // grid[i][j] ^ grid[i][0]: Check value of this bit if we were to toggle
                // the row to make the leftmost bit a 1 (if it's not already)
                countOnes += grid[i][j] ^ grid[i][0];
            }

            // Maximize the number of 1s in this column by considering the larger of countOnes and m-countOnes
            int maxOnes = max(countOnes, m - countOnes);

            // Add to result: multiply number of 1s by the value of this bit position
            result += maxOnes * (1 << (n - j - 1));
        }

        return result;
    }
};
