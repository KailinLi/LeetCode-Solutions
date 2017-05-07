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
    vector<TreeNode*> res;
public:
    void findNode(TreeNode* root, int val) {
        if (!root) return;
        if (root->val == val) res.push_back(root);
        findNode(root->left, val);
        findNode(root->right, val);
    }
    bool checkTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (s && t) {
            if (s->val == t->val) return checkTree(s->left, t->left) && checkTree(s->right, t->right);
            else return false;
        }
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!t) return false;
        findNode(s, t->val);
        for (auto st : res) {
            if (checkTree(st, t)) return true;
        }
        return false;
    }
};