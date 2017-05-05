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
    int res = 0;
public:
    void count(TreeNode* root, int sum) {
        if (!root) return;
        sum *= 10;
        sum += root->val;
        if (!root->left && !root->right) {
            res += sum;
            return;
        }
        count(root->left, sum);
        count(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        count(root, 0);
        return res;
    }
};