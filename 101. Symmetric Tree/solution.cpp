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
    bool judgement(TreeNode* left, TreeNode* right) {
        return (!left && !right)? true:(!left || !right)? false:left->val==right->val && ((left->left && right->right)?left->left->val==right->right->val:(!left->left && !right->right)?true:false) && ((left->right && right->left)?left->right->val==right->left->val:(!left->right && !right->left)?true:false) && judgement(left->left, right->right) && judgement(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return (!root)? true: judgement(root->left, root->right);
    }
};