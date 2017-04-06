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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>get;
        if (root == NULL) {
            return get;
        }
        vector<int>left = inorderTraversal(root->left);
        for (auto index : left) {
            get.push_back(index);
        }
        get.push_back(root->val);
        vector<int>right = inorderTraversal(root->right);
        for (auto index : right) {
            get.push_back(index);
        }
        return get;
    }
};