/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNode* head = (ListNode*) malloc(sizeof(ListNode)), *p = head;

    int c = 0;
    while (l1 || l2 || c) {
        if (l1) c += l1->val, l1 = l1->next;
        if (l2) c += l2->val, l2 = l2->next;
        p = (p->next = (ListNode*) malloc(sizeof(ListNode)));
        p->val = c % 10;
        p->next = NULL;
        c /= 10;
    }

    return head->next;
}
