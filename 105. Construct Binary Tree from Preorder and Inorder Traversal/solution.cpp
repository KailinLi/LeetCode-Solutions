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
    int index = 0;
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int begin, int length) {
        if (length == 0) return nullptr;
        int i = begin;
        while (inorder[i] != preorder[index]) i++;
        TreeNode* get = new TreeNode(inorder[i]);
        index++;
        get->left = build(preorder, inorder, begin, i - begin);
        get->right = build(preorder, inorder, i + 1, length - i + begin - 1);
        return get;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, (int)preorder.size());
    }
};
