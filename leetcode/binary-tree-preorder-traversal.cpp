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
    vector<int> preorderTraversal (TreeNode *root) {
        vector<int> v;
        stack<TreeNode *> stk;

        while (root || !stk.empty() ) {
            if (root) {
                stk.push (root);
                v.push_back (root->val);
                root = root->left;
            } else {
                root = stk.top()->right;
                stk.pop();
            }
        }

        return v;
    }
};