struct AVLNode {
    long val;
    int rightNodes;
    int high;
    AVLNode* left;
    AVLNode* right;
    AVLNode(long v): val(v), rightNodes(0), high(0), left(nullptr), right(nullptr) {}
};
struct AVLTree {
public:
    AVLNode* root;
    void insert(long value) {
        root = helpInsert(root, value);
    }
    int findMax(long key) {
        return helpFind(root, key);
    }
    AVLTree(long v) {
        root = new AVLNode(v);
    }
private:
    AVLNode* rotateLeft (AVLNode* root) {
        AVLNode* tmp = root->left;
        root->left = tmp->right;
        tmp->right = root;
        tmp->rightNodes += root->rightNodes + 1;
        root->high = max(height(root->left), height(root->right)) + 1;
        tmp->high = max(height(tmp->left), height(tmp->right)) + 1;
        return tmp;
    }
    AVLNode* rotateRight (AVLNode* root) {
        AVLNode* tmp = root->right;
        root->right = tmp->left;
        tmp->left = root;
        root->rightNodes -= (tmp->rightNodes + 1);
        root->high = max(height(root->left), height(root->right)) + 1;
        tmp->high = max(height(tmp->left), height(tmp->right)) + 1;
        return tmp;
    }
    AVLNode* doubleLeft (AVLNode* root) {
        root->left = rotateRight(root->left);
        return rotateLeft(root);
    }
    AVLNode* doubleRight (AVLNode* root) {
        root->right = rotateLeft(root->right);
        return rotateRight(root);
    }
    int height(AVLNode* avl) {
        if (!avl) return -1;
        else return avl->high;
    }
    AVLNode* helpInsert(AVLNode* root, long value) {
        if (!root) {
            root = new AVLNode(value);
        }
        else if (value < root->val) {
            root->left = helpInsert(root->left, value);
            if (height(root->left) - height(root->right) == 2) {
                if (value < root->left->val) {
                    root = rotateLeft(root);
                }
                else {
                    root = doubleLeft(root);
                }
            }
        }
        else {
            ++root->rightNodes;
            root->right = helpInsert(root->right, value);
            if (height(root->right) - height(root->left) == 2) {
                if (value >= root->right->val) {
                    root = rotateRight(root);
                }
                else {
                    root = doubleRight(root);
                }
            }
        }
        root->high = max(height(root->left), height(root->right)) + 1;
        return root;
    }
    int helpFind(AVLNode* root, long key) {
        if (!root) return -1;
        int res = 0;
        while (root) {
            if (root->val > key) {
                res += root->rightNodes + 1;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return res;
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        AVLTree avl(nums[0]);
        int res = 0;
        for (int j = 1; j < nums.size(); ++j) {
            res += avl.findMax(2 * static_cast<long>(nums[j]));
            avl.insert(static_cast<long>(nums[j]));
        }
        return res;
    }
};