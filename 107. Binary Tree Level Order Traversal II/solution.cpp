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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>neighbour;
        if (!root) {
            return res;
        }
        neighbour.push(root);
        while (!neighbour.empty()) {
            vector<int>tmp;
            int i = neighbour.size();
            while (i > 0) {
                TreeNode* tmpPoint = neighbour.front();
                neighbour.pop();
                tmp.push_back(tmpPoint->val);
                if (tmpPoint->left) neighbour.push(tmpPoint->left);
                if (tmpPoint->right) neighbour.push(tmpPoint->right);
                i--;
            }
            res.insert(res.begin(), tmp);
        }
        return res;
    }
};