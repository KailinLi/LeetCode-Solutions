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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        while (n != 0) {
            tail = tail->next;
            n--;
        }
        ListNode* current = head;
        ListNode* before = nullptr;
        while (tail != nullptr) {
            before = current;
            current = current->next;
            tail = tail->next;
        }
        if (current == head) {
            return current->next;
        }
        else {
            before->next = current->next;
            return head;
        }
    }
};