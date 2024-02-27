**
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
    int diameterOfBinaryTree(TreeNode* root) {
       
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    // A helper function to calculate the height of a tree
    // and update the diameter.
    int height(TreeNode* node, int& diameter) {
        if (node == NULL) return 0;
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        
        // Update the diameter if leftHeight + rightHeight is larger
        diameter = max(diameter, leftHeight + rightHeight);
        
        return 1 + max(leftHeight, rightHeight);
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    return node;
}
