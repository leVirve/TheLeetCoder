struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

template <size_t N>
ListNode* create_list(int (&arr)[N])
{
    ListNode *node = new ListNode(arr[0]);
    ListNode *p = node;
    for (int i = 1; i < N; ++i, p = p->next)
        p->next = new ListNode(arr[i]);
    return node;
}


bool is_equal(ListNode* p, ListNode* q)
{
    for (; p && q; p = p->next, q = q->next)
        if (p->val != q->val) return false;
    return p == q;
}


void print_list(ListNode* p)
{
    for (; p; p = p->next) printf("%d ", p->val);
    puts("");
}
