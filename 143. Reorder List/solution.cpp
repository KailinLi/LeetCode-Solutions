/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    stack<ListNode*>s;
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* second = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            second = second->next;
        }
        fast = second;
        while (second) {
            s.push(second);
            second = second->next;
        }
        second = head;
        while (second && !s.empty()) {
            ListNode* get = s.top();
            get->next = second->next;
            second->next = get;
            s.pop();
            second = get->next;
        }
        if (second) second->next = nullptr;
    }
};