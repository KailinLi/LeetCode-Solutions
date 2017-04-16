/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* p = head;
        ListNode* current = head->next;
        while (current) {
            if (current->val == p->val) {
                p->next = current->next;
                current = current->next;
                continue;
            }
            else {
                current = current->next;
                p = p->next;
            }
        }
        return head;
    }
};