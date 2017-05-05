/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        while (root->left) {
            TreeLinkNode* line = root;
            line->left->next = line->right;
            while (line->next) {
                line->right->next = line->next->left;
                line = line->next;
                line->left->next = line->right;
            }
            root = root->left;
        }
    }
};