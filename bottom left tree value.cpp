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
    int findBottomLeftValue(TreeNode* root) {
         if (!root) return -1; // Return -1 or throw an exception if the root is null

    queue<TreeNode*> q;
    q.push(root);

    int result = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            // For the first node of each level, update the result
            if (i == 0) result = node->val;

            // Push the left and then right child to the queue
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return result;
        
    }
};
