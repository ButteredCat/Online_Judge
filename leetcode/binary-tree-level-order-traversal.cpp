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
    vector<vector<int> > levelOrder(TreeNode *root) {
        if(root == nullptr) {
            vector<vector<int> > emptyTree;
            return emptyTree;
        }

        vector<TreeNode*> aLevel(1, root);
        vector<vector<TreeNode*> > tree(1, aLevel);
        while(!isLastLevel(aLevel)) {
            aLevel = getNextLevel(aLevel);
            tree.push_back(aLevel);
        }
        return getValues(tree);
    }
private:
    inline bool isLastLevel(const vector<TreeNode *> &level) {
        for (auto eachNode: level) {
            if (eachNode != nullptr && !isLeaf(eachNode))
                return false;
        }
        return true;
    }

    inline bool isLeaf(TreeNode *node) {
        return node->left == nullptr && node->right == nullptr;
    }

    vector<TreeNode *> getNextLevel(const vector<TreeNode *> &level) {
        vector<TreeNode *> nextLevel;
        for(auto eachNode: level) {
            if(eachNode->left != nullptr)
                nextLevel.push_back(eachNode->left);
            if(eachNode->right != nullptr)
                nextLevel.push_back(eachNode->right);
        }
        return nextLevel;
    }

    vector<vector<int> > getValues(const vector<vector<TreeNode*> > &tree) {
        vector<vector<int> > treeValues;
        for(auto eachLevel: tree) {
            vector<int> valOfLevel;
            for(auto eachNode: eachLevel) {
                if(eachNode != nullptr) {
                    valOfLevel.push_back(eachNode->val);
                }
            }
            treeValues.push_back(valOfLevel);
        }
        return treeValues;
    }
};
