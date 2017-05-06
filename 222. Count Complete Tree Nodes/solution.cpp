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
    int countLeft(TreeNode* root) {
        int count = 0;
        while(root) {
            root = root->left;
            count++;
        }
        return count;
    }
    int countRight(TreeNode* root) {
        int count = 0;
        while (root) {
            root = root->right;
            count++;
        }
        return count;
    }
    int myCount(TreeNode* root, int lastLeft, int lastRight) {
        if (!root) return 0;
        int left = lastLeft ? lastLeft - 1 : countLeft(root);
        int right = lastRight ? lastRight - 1 : countRight(root);
        if (left == right) return pow(2, left) - 1;
        return 1 + myCount(root->left, left, 0) + myCount(root->right, 0, right);
    }
    int countNodes(TreeNode* root) {
        return myCount(root, 0, 0);
    }
};