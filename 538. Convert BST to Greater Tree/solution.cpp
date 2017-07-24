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
    int sum = 0;
    void getSum (TreeNode* root) {
        if (!root) return;
        getSum(root->right);
        sum += root->val;
        root->val = sum;
        getSum(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        getSum(root);
        return root;
    }
};