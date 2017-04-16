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
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        else if (!head->next) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head->next;
        ListNode* tmp = swapPairs(head->next->next);
        dummy.next->next = head;
        head->next = tmp;
        return dummy.next;
    }
};