/**
  *
  * Given a binary tree, find its minimum depth.
  *
  * The minimum depth is the number of nodes along the shortest path from the
  * root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        if(root == nullptr)
            return 0;

        if(isLeafNode(root))
            return 1;
        else if(hasOnlyOneChild(root))
            return 1 + minDepth(root->left==nullptr ? root->right : root->left);
        else
            return 1 + min(minDepth(root->left), minDepth(root->right));
    }
private:
    bool isLeafNode(TreeNode *node) {
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }
    bool hasOnlyOneChild(TreeNode *node) {
        return node != nullptr
               && ((node->left==nullptr && node->right!=nullptr)
                   || (node->left!=nullptr && node->right==nullptr));
    }
};
