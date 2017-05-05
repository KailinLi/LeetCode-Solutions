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
    int index;
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int begin, int length) {
        if (length == 0) return nullptr;
        int i = 0;
        while (inorder[i] != postorder[index]) i++;
        index--;
        TreeNode* get = new TreeNode(inorder[i]);
        get->right = build(inorder, postorder, i + 1, length - i + begin - 1);
        get->left = build(inorder, postorder, begin, i - begin);
        return get;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index = (int)postorder.size() - 1;
        return build(inorder, postorder, 0, (int)inorder.size());
    }
};
