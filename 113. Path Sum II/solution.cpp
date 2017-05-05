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
    vector<vector<int>> res;
public:
    void pSum(vector<int> &path, TreeNode* root, int sum) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && !(sum - root->val)) res.push_back(path);
        pSum(path, root->left, sum - root->val);
        pSum(path, root->right, sum - root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>p;
        pSum(p, root, sum);
        return res;
    }
};