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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return pathSum(root->left, sum) + pathSum(root->right, sum) + pathSumFrom(root, sum);
    }
    int pathSumFrom(TreeNode* root, int sum) {
        if (!root) return 0;
        return ((root->val == sum) ? 1 : 0) + pathSumFrom(root->left, sum - root->val) + pathSumFrom(root->right, sum - root->val);
    }
};