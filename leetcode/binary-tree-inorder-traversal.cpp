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
    vector<int> inorderTraversal (TreeNode *root) {
        vector<int> v;
        stack<TreeNode *> stk;

        while (root || !stk.empty() ) {
            if (root) {
                stk.push (root);
                root = root->left;
            } else {
                v.push_back (stk.top()->val);
                root = stk.top()->right;
                stk.pop();
            }
        }

        return v;
    }
};