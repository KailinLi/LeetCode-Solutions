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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* second = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            second = second->next;
            if (fast == second) {
                break;
            }
        }
        if (fast && fast->next) {
            fast = head;
            while (fast != second) {
                fast = fast->next;
                second = second->next;
            }
            return fast;
        }
        return nullptr;
    }
};