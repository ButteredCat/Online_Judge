/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth (TreeNode *root) {
        if (root == NULL) {
            return 0;
        } else {
            int depthOfLeft = maxDepth (root->left);
            int depthOfRight = maxDepth (root->right);
            return depthOfLeft > depthOfRight ? depthOfLeft + 1 : depthOfRight + 1;
        }
    }
};
