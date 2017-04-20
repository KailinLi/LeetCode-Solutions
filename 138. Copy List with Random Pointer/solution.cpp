/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* p = head;
        while (p) {
            RandomListNode* q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }
        p = head;
        while (p) {
            if (p->random) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        RandomListNode dummy(0);
        RandomListNode* q = &dummy;
        p = head;
        while (p) {
            q->next = p->next;
            q = q->next;
            p->next = p->next->next;
            p = p->next;
        }
        return dummy.next;
    }
};