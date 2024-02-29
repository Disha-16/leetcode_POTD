/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
    q.push(root);
    int level = 0; // Start from level 0

    while (!q.empty()) {
        int levelSize = q.size();
        int prevValue = (level % 2 == 0) ? INT_MIN : INT_MAX; // Set initial previous value based on level
        
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            // Check the even/odd level conditions
            if (level % 2 == 0) {
                // For even-indexed levels, values must be odd and strictly increasing
                if (node->val % 2 == 0 || node->val <= prevValue) return false;
            } else {
                // For odd-indexed levels, values must be even and strictly decreasing
                if (node->val % 2 != 0 || node->val >= prevValue) return false;
            }
            prevValue = node->val; // Update previous value for next iteration

            // Add children to the queue for the next level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ++level; // Move to the next level
    }

    return true;
 }   
};
