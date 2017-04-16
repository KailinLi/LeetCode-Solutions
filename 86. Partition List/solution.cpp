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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummyL(0);
        ListNode dummyR(0);
        ListNode* l = &dummyL;
        ListNode* r = &dummyR;
        ListNode* p = head;
        while (p) {
            if (p->val < x) {
                l->next = p;
                l = l->next;
            }
            else {
                r->next = p;
                r = r->next;
            }
            p = p->next;
        }
        r->next = nullptr;
        if (!dummyL.next) {
            return dummyR.next;
        }
        else {
            l->next = dummyR.next;
            return dummyL.next;
        }
    }
};