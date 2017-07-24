#include "../framework/header.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#ifdef C_SOLUTION
#include "solution.h"
#else
#include "solution.hpp"
#endif

ListNode* solve(ListNode* a, int k) {
#ifdef C_SOLUTION
    return rotateRight(a, k);
#else
    Solution s;
    return s.rotateRight(a, k);
#endif
}


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


TEST_CASE( "rotate numbers [1,2,3,4,5]", "[rotateRight]" ) {
    int l1[] = {1, 2, 3, 4, 5},
        a1[] = {4, 5, 1, 2, 3},
        a2[] = {2, 3, 4, 5, 1},
        a3[] = {1, 2, 3, 4, 5},
        a4[] = {5, 1, 2, 3, 4};
    ListNode *in,
             *ans1 = create_list(a1),
             *ans2 = create_list(a2),
             *ans3 = create_list(a3),
             *ans4 = create_list(a4);

    REQUIRE( is_equal(solve(in = create_list(l1), 2), ans1) );
    REQUIRE( is_equal(solve(in = create_list(l1), 4), ans2) );
    REQUIRE( is_equal(solve(in = create_list(l1), 5), ans3) );
    REQUIRE( is_equal(solve(in = create_list(l1), 6), ans4) );
}


TEST_CASE( "rotate numbers []", "[rotateRight]" ) {
    ListNode *in = NULL,
             *ans1 = NULL;

    REQUIRE( is_equal(solve(in, 0), ans1) );
}
