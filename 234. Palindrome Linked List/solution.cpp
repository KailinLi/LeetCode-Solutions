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
    bool isPalindrome(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        while (first && first->next) {
            first = first->next->next;
            second = second->next;
        }
        ListNode* p = reverseList(second);
        second = head;
        while (p) {
            if (second->val != p->val) {
                return false;
            }
            p = p->next;
            second = second->next;
        }
        return true;
    }
};