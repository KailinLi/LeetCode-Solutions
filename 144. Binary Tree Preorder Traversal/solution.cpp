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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>answer;
        stack<TreeNode*>point;
        TreeNode *current = root;
        while (current || !point.empty()) {
            if (current) {
                answer.push_back(current->val);
                point.push(current);
                current = current->left;
            }
            else {
                current = point.top();
                point.pop();
                current = current->right;
            }
        }
        return answer;
    }
};