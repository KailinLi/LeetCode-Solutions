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
    bool hasPathSum(TreeNode* root, int sum) {
        return (!root)?false:(sum - root->val == 0 && !root->left && !root->right)?true:(root->left?hasPathSum(root->left, sum - root->val):false) || (root->right?hasPathSum(root->right, sum - root->val):false);
    }
};