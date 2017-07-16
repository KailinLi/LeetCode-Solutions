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
    map<int, int> dic;
    void helpFind(TreeNode* root) {
        if (!root) return;
        auto res = dic.insert({root->val, 1});
        if (!res.second) ++res.first->second;
        helpFind(root->left);
        helpFind(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        helpFind(root);
        vector<int> res;
        int count = INT32_MIN;
        for_each(dic.begin(), dic.end(), [&](pair<int, int> item) {
            if (count < item.second) {
                count = item.second;
                res.clear();
                res.push_back(item.first);
            }
            else if (count == item.second) res.push_back(item.first);
        });
        return res;
    }
};