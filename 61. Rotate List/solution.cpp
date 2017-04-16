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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode* p = head;
        int sum = 0;
        while (p) {
            sum++;
            p = p->next;
        }
        p = head;
        k %= sum;
        sum -= k;
        while (sum > 1) {
            p = p->next;
            if (!p) {
                p = head;
            }
            sum--;
        }
        if (!p->next) return head;
        ListNode* last = p->next;
        while (last->next) last = last->next;
        last->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};