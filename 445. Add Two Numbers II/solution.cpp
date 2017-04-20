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
    ListNode* solve(ListNode* p1, int n1, ListNode* p2, int n2) {
        ListNode *p, *q;
        if (!n1 && !n2) {
            return nullptr;
        }
        if (n1 > n2) {
            p = solve(p1->next, n1 - 1, p2, n2);
            q = new ListNode(p1->val);
        }
        else {
            p = solve(p1->next, n1 - 1, p2->next, n2 - 1);
            q = new ListNode(p1->val + p2->val);
        }
        if (p && p->val > 9) {
            ++q->val;
            p->val -= 10;
        }
        q->next = p;
        return q;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0;
        for (auto p = l1; p; p = p->next) {
            n1++;
        }
        for (auto p = l2; p; p = p->next) {
            n2++;
        }
        if (n1 < n2) {
            swap(l1, l2);
            swap(n1, n2);
        }
        auto p = solve(l1, n1, l2, n2);
        if (p->val > 9) {
            p->val -= 10;
            auto q = new ListNode(1);
            q->next = p;
            p = q;
        }
        return p;
    }
};