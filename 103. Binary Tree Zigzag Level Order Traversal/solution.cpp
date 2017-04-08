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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>answer;
        if (root == NULL) {
            return answer;
        }
        vector<TreeNode*>neighbor;
        vector<TreeNode*>current;
        current.push_back(root);
        bool ifFromLeft = true;
        while (!current.empty()) {
            vector<int>tmp;
            neighbor.clear();
            if (ifFromLeft) {
                for (int index = 0; index < current.size(); index++) {
                    tmp.push_back(current[index]->val);
                    if (current[current.size() - 1 - index]->right) neighbor.push_back(current[current.size() - 1 - index]->right);
                    if (current[current.size() - 1 - index]->left) neighbor.push_back(current[current.size() - 1 - index]->left);
                }
                ifFromLeft = false;
            }
            else {
                for (int index = 1; index <= current.size(); index++) {
                    tmp.push_back(current[index - 1]->val);
                    if (current[current.size() - index]->left) neighbor.push_back(current[current.size() - index]->left);
                    if (current[current.size() - index]->right) neighbor.push_back(current[current.size() - index]->right);
                }
                ifFromLeft = true;
            }
            current = neighbor;
            answer.push_back(tmp);
        }
        return answer;
    }
};