/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if (!root) return res;
        auto left = binaryTreePaths(root->left);
        auto right = binaryTreePaths(root->right);
        if (left.empty() && right.empty()) {
            res.push_back(to_string(root->val));
            return res;
        }
        for (auto s : left) {
            res.push_back(to_string(root->val) + "->" + s);
        }
        for (auto s : right) {
            res.push_back(to_string(root->val) + "->" + s);
        }
        return res;
    }
};