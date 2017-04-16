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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        else if (lists.size() == 1) {
            return lists[0];
        }
        else {
            auto split = lists.size() / 2;
            vector<ListNode*>one(split);
            vector<ListNode*>two(lists.size() - split);
            copy(lists.begin(), lists.begin()+split, one.begin());
            copy(lists.begin()+split, lists.end(), two.begin());
            ListNode* l1 = mergeKLists(one);
            ListNode* l2 = mergeKLists(two);
            ListNode newList(0);
            ListNode* tmp  = &newList;
            while (l1 && l2) {
                if (l1->val > l2->val) {
                    tmp->next = l2;
                    l2 = l2->next;
                    tmp = tmp->next;
                }
                else {
                    tmp->next = l1;
                    l1 = l1->next;
                    tmp = tmp->next;
                }
            }
            if (l1) tmp->next = l1;
            else tmp->next = l2;
            return newList.next;
        }
    }
};