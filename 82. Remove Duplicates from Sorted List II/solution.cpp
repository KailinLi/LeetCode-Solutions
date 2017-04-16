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
        ListNode dummy(0);
        ListNode* p = &dummy;
        ListNode* current = head;
        while (current) {
            while (current->next && current->next->val == current->val) {
                while (current->next && current->next->val == current->val) {
                    current->next = current->next->next;
                }
                current = current->next;
                if (!current) break;
            }
            p->next = current;
            if (!current) break;
            current = current->next;
            p = p->next;
        }
        return dummy.next;
    }
};