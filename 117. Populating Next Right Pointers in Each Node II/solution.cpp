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
        queue<TreeLinkNode*>q;
        q.push(root);
        while (!q.empty()) {
            auto count = q.size();
            while (count > 0) {
                TreeLinkNode* tmp = q.front();
                q.pop();
                tmp->next = (count == 1) ? nullptr : q.front();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
                count--;
            }
        }
    }
};