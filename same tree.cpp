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
    bool isSameTree(TreeNode* p, TreeNode* q) {
         if (!p && !q) return true;
        // If one is NULL and the other isn't, they aren't the same
        if (!p || !q) return false;
        // If their values differ, they aren't the same
        if (p->val != q->val) return false;
        // Recursively check if left subtrees and right subtrees are the same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
    }
};
