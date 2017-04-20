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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 && p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1) {
            p2 = headA;
            while (p1) {
                p1 = p1->next;
                p2 = p2->next;
            }
            p1 = headB;
        }
        else {
            p1 = headB;
            while (p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
            p2 = headA;
        }
        while (p1) {
            if (p1 == p2) {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};