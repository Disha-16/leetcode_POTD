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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesHelper(root, false);
    }
    
private:
    int sumOfLeftLeavesHelper(TreeNode* node, bool isLeft) {
        if (!node) {
            return 0;
        }
        // Check if it's a leaf node
        if (!node->left && !node->right) {
            if (isLeft) {
                return node->val;  // It's a left leaf
            } else {
                return 0;  // It's a right leaf or a single root without children
            }
        }
        // Recursively sum left leaves from left and right subtrees
        return sumOfLeftLeavesHelper(node->left, true) + sumOfLeftLeavesHelper(node->right, false);
    }
};

// Helper function to create a new node
TreeNode* newNode(int value) {
    return new TreeNode(value);
        
    }
