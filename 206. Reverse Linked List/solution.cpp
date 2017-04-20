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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* save;
        first->next = nullptr;
        while (second) {
            save = second->next;
            second->next = first;
            first = second;
            second = save;
        }
        return first;
    }
};