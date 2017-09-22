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
    map<int, int> frequence;
    int maxValue;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxValue = 0;
        caculateSum(root);
        vector<int> res;
        for (auto i = frequence.begin(); i != frequence.end(); ++i) {
            if (i->second == maxValue) res.push_back(i->first);
        }
        return res;
    }
    int caculateSum(TreeNode* root) {
        if (!root) return 0;
        int tmp = root->val + caculateSum(root->left) + caculateSum(root->right);
        maxValue = max(maxValue, ++frequence[tmp]);
        return tmp;
    }
};