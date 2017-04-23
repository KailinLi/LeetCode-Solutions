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
    int sum (TreeNode* root) {
        if (!root) return 0;
        return sum(root->left) + sum(root->right) + root->val;
    }
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        return findTilt(root->left) + findTilt(root->right) + abs(sum(root->left) - sum(root->right));
    }
};