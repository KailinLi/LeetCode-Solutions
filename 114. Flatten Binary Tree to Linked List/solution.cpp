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
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* current = root;
        stack<TreeNode*>s;
        while (current) {
            if (!current->left) {
                if (!current->right) {
                    if (s.empty()) break;
                    else {
                        current->right = s.top();
                        s.pop();
                        current = current->right;
                        continue;
                    }
                }
                current = current->right;
                continue;
            }
            if (current->right) s.push(current->right);
            current->right = current->left;
            current->left = nullptr;
            current = current->right;
        }
    };
};