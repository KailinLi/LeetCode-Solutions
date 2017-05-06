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
private:
    int maxP = INT_MIN;
public:
    int getMax(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        if (!root->left || !root->right) {
            int son = root->left ? getMax(root->left) : getMax(root->right);
            maxP = max(maxP, max(son, son + root->val));
            return max(son + root->val, root->val);
        }
        int left = getMax(root->left);
        int right = getMax(root->right);
        maxP = max(maxP, max(max(left, right), left + right + root->val));
        return max(max(left + root->val, right + root->val), root->val);
    }
    int maxPathSum(TreeNode* root) {
        return max(getMax(root), maxP);
    }
};