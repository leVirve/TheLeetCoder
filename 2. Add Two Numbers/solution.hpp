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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *node = new ListNode(0), *p = node;

        while (l1 || l2) {
            int c = p->val;
            if (l1) c += l1->val, l1 = l1->next;
            if (l2) c += l2->val, l2 = l2->next;
            p->val = c % 10;
            if (!(c / 10) && (!l1 && !l2)) break;
            p = (p->next = new ListNode(c / 10));
        }

        return node;
    }
};
