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
        ListNode node(0), *p = &node;

        int c = 0;
        while (l1 || l2 || c) {
            if (l1) c += l1->val, l1 = l1->next;
            if (l2) c += l2->val, l2 = l2->next;
            p = (p->next = new ListNode(c % 10));
            c /= 10;
        }

        return node.next;
    }
};
