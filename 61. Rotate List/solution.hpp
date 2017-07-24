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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int num = 1;
        ListNode *p = head, *q;

        while (p->next) p = p->next, num++;
        p->next = head;

        k %= num;
        for (int i = 0; i < num - k; ++i) p = p->next;
        q = p->next;
        p->next = NULL;

        return q;
    }
};
