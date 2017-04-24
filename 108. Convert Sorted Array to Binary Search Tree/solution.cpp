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
    vector<int>list;
public:
    TreeNode* toBST(int begin, int length) {
        if (length == 1) {
            TreeNode* res = new TreeNode(list[begin]);
            return res;
        }
        else if (length == 2) {
            TreeNode* res = new TreeNode(list[begin + 1]);
            TreeNode* next = new TreeNode(list[begin]);
            res->left = next;
            return res;
        }
        int middle = length / 2;
        TreeNode* res = new TreeNode(list[middle + begin]);
        res->left = toBST(begin, middle);
        res->right = toBST(middle + 1 + begin, length - 1 - middle);
        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        list = nums;
        return toBST(0, (int)nums.size());
    }
};