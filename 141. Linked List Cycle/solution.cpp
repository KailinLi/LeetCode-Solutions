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
    bool hasCycle(ListNode *head) {
        ListNode* fast;
        ListNode* slow = head;
        if (head && head->next && head->next->next) fast = head->next->next;
        else return false;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow || fast == slow->next) return true;
        }
        return false;
    }
};