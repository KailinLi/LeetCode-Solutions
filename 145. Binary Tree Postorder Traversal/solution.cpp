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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>answer;
        stack<pair<TreeNode*, int>>point;
        pair<TreeNode*, int>current = {root, 0};    //'0':has not been visited,
                                                    //'1':left tree was visited, '2':all subtree were visited.
        while (current.first || !point.empty()) {
            if (current.first) {
                if (current.second == 0) {
                    current.second = 1;
                    point.push(current);
                    current.first = current.first->left;
                    current.second = 0;
                }
                else if (current.second == 1) {
                    current.second = 2;
                    point.push(current);
                    current.first = current.first->right;
                    current.second = 0;
                }
                else {
                    answer.push_back(current.first->val);
                    if (point.empty()) {
                        return answer;
                    }
                    else {
                        current = point.top();
                        point.pop();
                        continue;
                    }
                }
            }
            else {
                current = point.top();
                point.pop();
            }
        }
        return answer;
    }
};