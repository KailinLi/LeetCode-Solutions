/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string subStr(string &data, size_t &begin) {
        if (begin >= data.size() - 1) return "";
        int length = 0;
        size_t i = begin;
        while (data[i] != ',') {
            ++length;
            ++i;
        }
        string Msg = data.substr(begin, length);
        begin += length + 1;
        return Msg;
    }
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {
            int size = static_cast<int>(q.size());
            while (size--) {
                TreeNode* tmp = q.front();
                q.pop();
                res += ",";
                res += (tmp) ? to_string(tmp->val) : "n";
                if (tmp) {
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }
        }
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        size_t begin = 1;
        string getMsg = subStr(data, begin);
        cout << getMsg << endl;
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(stoi(getMsg));
        q.push(root);
        while (!q.empty()) {
            int size = static_cast<int>(q.size());
            while (size--) {
                TreeNode* tmp = q.front();
                q.pop();
                getMsg = subStr(data, begin);
                if (getMsg.empty()) break;
                if (getMsg != "n") {
                    TreeNode* node = new TreeNode(stoi(getMsg));
                    tmp->left = node;
                    q.push(node);
                }
                getMsg = subStr(data, begin);
                if (getMsg.empty()) break;
                if (getMsg != "n") {
                    TreeNode* node = new TreeNode(stoi(getMsg));
                    tmp->right = node;
                    q.push(node);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));