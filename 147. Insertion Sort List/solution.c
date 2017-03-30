/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode *core = head;
    struct ListNode *tmp;
    struct ListNode *cp;
    while (core->next != NULL) {
        if (core->next->val >= core->val) {
            core = core->next;
        }
        else {
            if (core == head) {
                head = core->next;
                tmp = head->next;
                head->next = core;
                core->next = tmp;
            }
            else {
                cp = head;
                if (cp->val > core->next->val) {
                    head = core->next;
                    tmp = core->next->next;
                    head->next = cp;
                    core->next = tmp;
                }
                else {
                    while (cp->next->val <= core->next->val) {
                        cp = cp->next;
                    }
                    tmp = core->next->next;
                    core->next->next = cp->next;
                    cp->next = core->next;
                    core->next = tmp;
                }
            }
        }
    }
    return head;
}