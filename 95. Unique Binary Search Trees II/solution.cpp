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
    TreeNode* change(TreeNode* root, int offset) {
        if (!root) return nullptr;
        TreeNode* get = new TreeNode(root->val + offset);
        get->left = change(root->left, offset);
        get->right = change(root->right, offset);
        return get;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>>res(n + 1);
        if (!n) return res[0];
        TreeNode* sample = new TreeNode(1);
        res[0].push_back(nullptr);
        res[1].push_back(sample);
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (auto l : res[j]) {
                    for (auto r : res[i - j - 1]) {
                        TreeNode* get = new TreeNode(j+1);
                        get->left = l;
                        get->right = change(r, j+1);
                        res[i].push_back(get);
                    }
                }
            }
        }
        return res[n];
    }
};
