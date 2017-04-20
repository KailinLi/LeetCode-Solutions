/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* change(ListNode* start, int length) {
        if (length == 1) {
            TreeNode* get = new TreeNode(start->val);
            return get;
        }
        else if (length == 2) {
            TreeNode* get = new TreeNode(start->next->val);
            TreeNode* next = new TreeNode(start->val);
            get->left = next;
            return get;
        }
        ListNode *p = start;
        int half = length / 2 + 1;
        for (int i = 1; i < half; i++) {
            p = p->next;
        }
        TreeNode* get = new TreeNode(p->val);
        get->left = change(start, half - 1);
        get->right = change(p->next, length - half);
        return get;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        int length = 0;
        while (p) {
            p = p->next;
            length++;
        }
        if (length == 0) return nullptr;
        return change(head, length);
    }
};