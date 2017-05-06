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
    TreeNode* getMax(TreeNode* first, TreeNode* second) {
        if (!first && !second) return nullptr;
        if (first && second) return first->val > second->val ? first : second;
        return first ? first : second;
    }
    TreeNode* getMin(TreeNode* first, TreeNode* second) {
        if (!first && !second) return nullptr;
        if (first && second) return first->val > second->val ? second : first;
        return first ? first : second;
    }
    TreeNode* maxNode(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* left = maxNode(root->left);
        TreeNode* right = maxNode(root->right);
        return getMax(getMax(left, right), root);
    }
    TreeNode* minNode(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* left = minNode(root->left);
        TreeNode* right = minNode(root->right);
        return getMin(getMin(left, right), root);
    }
    void recoverTree(TreeNode* root) {
        if (!root) return;
        TreeNode* left = maxNode(root->left);
        TreeNode* right = minNode(root->right);
        bool worryLeft =  left ? left->val > root->val : false;
        bool worryRight = right ? right->val < root->val : false;
        if (!worryLeft && !worryRight) {
            recoverTree(root->left);
            recoverTree(root->right);
        }
        else if (worryLeft && worryRight) {
            swap(left->val, right->val);
        }
        else if (worryLeft) {
            swap(left->val, root->val);
        }
        else {
            swap(right->val, root->val);
        }
        return;
    }
};