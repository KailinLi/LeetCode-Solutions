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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int index = 1;
        ListNode dummy(0);
        ListNode* p = &dummy;
        p->next = head;
        while (index < m) {
            p = p->next;
            index++;
        }
        ListNode* first = p->next;
        
        ListNode* second = first->next;
        ListNode* save = nullptr;
        while (index < n) {
            save = second->next;
            second->next = first;
            first = second;
            second = save;
            index++;
        }
        p->next->next = second;
        p->next = first;
        return dummy.next;
    }
};