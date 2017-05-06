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
    int count(TreeNode* root) {
        return root ? 1 + count(root->left) + count(root->right) : 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        int left = count(root->left);
        if (left == k - 1) return root->val;
        if (left < k - 1) return kthSmallest(root->right, k - left - 1);
        else return kthSmallest(root->left, k);
    }
};