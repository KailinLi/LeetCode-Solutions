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
    int numComponents(ListNode* head, vector<int>& G) {
        if (!head) return 0;
        int res = 0;
        sort(G.begin(), G.end());
        // bool if_before = binary_search(G.begin(), G.end(), head->val);
        bool flag = false;
        if (binary_search(G.begin(), G.end(), head->val)) {
            flag = true;
            ++res;
        }
        while (head->next) {
            head = head->next;
            if (binary_search(G.begin(), G.end(), head->val)) {
                if (!flag) {
                    ++res;
                    flag = true;
                }
            }
            else flag = false;
        }
        return res;
    }
};