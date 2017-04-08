/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<int>hash;
    int index = 0;
public:
    BSTIterator(TreeNode *root) {
        stack<TreeNode*>point;
        TreeNode *current = root;
        while (current || !point.empty()) {
            if (current) {
                point.push(current);
                current = current->left;
            }
            else {
                current = point.top();
                point.pop();
                hash.push_back(current->val);
                current = current->right;
            }
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < hash.size();
    }
    
    /** @return the next smallest number */
    int next() {
        return hash[index++];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */