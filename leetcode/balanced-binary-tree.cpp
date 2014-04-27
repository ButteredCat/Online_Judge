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
    bool isBalanced(TreeNode *root) {
        if(root==NULL) {
            return true;
        } else {
            int diff = abs(depth(root->left) - depth(root->right));
            // if diff>1, you don't need to check whether subtrees are balanced, which reduces much recursion
            return diff<=1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }

    int depth(TreeNode *root) {
        return root==NULL ? 0 : 1+max(depth(root->left), depth(root->right));
    }
};
