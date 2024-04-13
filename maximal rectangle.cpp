class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

    int maxArea = 0;
    vector<int> height(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == '0') {
                height[j] = 0;
            } else {
                height[j]++;
            }
        }

        // Calculate maximum area for the current histogram
        stack<int> st;
        for (int k = 0; k <= height.size(); ++k) {
            while (!st.empty() && (k == height.size() || height[st.top()] > height[k])) {
                int h = height[st.top()];
                st.pop();
                int w = st.empty() ? k : k - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(k);
        }
    }
    return maxArea;
        
    }
};
