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
    int DFS(TreeNode* root) {
        if (!root) return 0;
        int leftHigh = DFS(root->left);
        if (leftHigh == -1) return -1;
        int rightHigh = DFS(root->right);
        if (rightHigh == -1) return -1;
        if (abs(leftHigh - rightHigh) > 1) return -1;
        return max(leftHigh, rightHigh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return DFS(root) != -1;
    }
};