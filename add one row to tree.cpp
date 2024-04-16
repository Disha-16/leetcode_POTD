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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
        // If depth is 1, create a new root and make the original tree as left child of new root
        TreeNode* newRoot = new TreeNode(v);
        newRoot->left = root;
        return newRoot;
    }

    queue<TreeNode*> q;
    q.push(root);
    int currentDepth = 1;

    // Traverse till the level just before the desired depth
    while (currentDepth < d - 1) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ++currentDepth;
    }

    // We are now at level depth-1 and can add new nodes
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        // Create new nodes and rearrange pointers
        TreeNode* tmpLeft = node->left;
        TreeNode* tmpRight = node->right;
        node->left = new TreeNode(v);
        node->right = new TreeNode(v);
        node->left->left = tmpLeft;
        node->right->right = tmpRight;
    }

    return root;
        
    }
};
