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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> array;
        ListNode* p = head;
        while (p != NULL) {
            array.push_back(p->val);
            p = p->next;
        }
        for (int i = 0; i < array.size(); i++) {
            int j = i -1;
            int tmp = array[i];
            for (; j >= 0 && array[j] > tmp; j--) {
                array[j+1] = array[j];
                array[j] = tmp;
            }
        }
        p = head;
        int index = 0;
        while (p != NULL) {
            p->val = array[index];
            index++;
            p = p->next;
        }
        return head;
    }
};