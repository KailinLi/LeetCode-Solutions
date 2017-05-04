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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if (!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {
            auto size = q.size();
            vector<int>tmp;
            for (auto i = 0; i < size; i++) {
                TreeNode* get = q.front();
                tmp.push_back(get->val);
                q.pop();
                if (get->left) q.push(get->left);
                if (get->right) q.push(get->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};