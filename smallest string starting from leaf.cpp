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
    string smallestFromLeaf(TreeNode* root) {
         string smallest = "~"; // A string larger than any possible valid result (since `z` is the largest character we handle).
        dfs(root, "", smallest);
        return smallest;
    }
    
    void dfs(TreeNode* node, string current, string& smallest) {
        if (!node) return;
        // Append current node's character to the path string
        current = char('a' + node->val) + current;
        
        // Check if it's a leaf node
        if (!node->left && !node->right) {
            if (current < smallest) {
                smallest = current;
            }
            return;
        }
        
        // Recur for left and right children
        if (node->left) dfs(node->left, current, smallest);
        if (node->right) dfs(node->right, current, smallest);
    }
};
