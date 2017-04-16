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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        else if (k == 1) return head;
        ListNode* last = head;
        int t = k;
        while (t > 1) {
            if (!(last->next)) return head;
            last = last->next;
            t--;
        }
        ListNode dummy(0);
        ListNode* tmp = &dummy;
        tmp->next = last;
        ListNode* next = reverseKGroup(last->next, k);
        ListNode* p = head->next, * before = head, *save;
        while (p != last) {
            save = p->next;
            p->next = before;
            before = p;
            p = save;
        }
        last->next = before;
        head->next = next;
        return dummy.next;
    }
};