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
    int maxD = 0;
public:
    int DFS(TreeNode* root) {
        if (!root) return 0;
        int leftPath = DFS(root->left);
        int rightPath = DFS(root->right);
        if (maxD < leftPath + rightPath) maxD = leftPath + rightPath;
        return max(leftPath, rightPath) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root);
        return maxD;
    }
};