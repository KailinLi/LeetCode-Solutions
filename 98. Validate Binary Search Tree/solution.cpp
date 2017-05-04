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
    bool test(TreeNode* root, long min, long max) {
        if (!root) return true;
        if (root->val >= max || root->val <= min) return false;
        return test(root->left, min, root->val) && test(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return test(root, LONG_MIN, LONG_MAX);
    }
};