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
    ListNode* merge(ListNode* S, ListNode* M, ListNode* L) {
        ListNode* endM = M;
        while (endM->next != NULL) {
            endM = endM->next;
        }
        if (S == NULL) {
            endM->next = L;
            return M;
        }
        ListNode* p = S;
        while (p->next != NULL) {
            p = p->next;
        }
        if (L == NULL) {
            p->next = M;
            return S;
        }
        else {
            p->next = M;
            endM->next = L;
            return S;
        }
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *p = head->next;
        int pick = head->val;
        ListNode *S = NULL;
        ListNode *Sp = NULL;
        ListNode *L = NULL;
        ListNode *Lp = NULL;
        ListNode *M = head;
        ListNode *Mp = M;
    
        while (p != NULL) {
            if (p->val < pick) {
                if (!S) {
                    S = p;
                    Sp = S;
                }
                else {
                    Sp->next = p;
                    Sp = Sp->next;
                }
            }
            else if (p->val > pick) {
                if (!L) {
                    L = p;
                    Lp = L;
                }
                else {
                    Lp->next = p;
                    Lp = Lp->next;
                }
            }
            else {
                Mp->next = p;
                Mp = Mp->next;
            }
            p = p->next;
        }
        if (Sp != NULL)
            Sp->next = NULL;
        else
            Sp = NULL;
        if (Lp != NULL)
            Lp->next = NULL;
        else
            Lp = NULL;
        if (Mp != NULL)
            Mp->next = NULL;
        else
            Mp = NULL;
        return merge(sortList(S), head, sortList(L));
    }
};