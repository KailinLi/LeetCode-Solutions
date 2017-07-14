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
    string res;
public:
    string tree2str(TreeNode* t) {
        toString(t);
        return res;
    }
    void toString(TreeNode* t) {
        if (!t) return;
        res += to_string(t->val);
        if (!t->left && !t->right) return;
        else if (!t->left) {
            res += "()(";
            toString(t->right);
            res += ")";
        }
        else if (!t->right) {
            res += "(";
            toString(t->left);
            res += ")";
        }
        else {
            res += "(";
            toString(t->left);
            res += ")(";
            toString(t->right);
            res += ")";
        }
    }
};