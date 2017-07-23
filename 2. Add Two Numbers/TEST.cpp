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

ListNode* solve(ListNode* a, ListNode* b) {
#ifdef C_SOLUTION
    return addTwoNumbers(a, b);
#else
    Solution s;
    return s.addTwoNumbers(a, b);
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


TEST_CASE( "add two numbers [243]+[564]", "[addTwoNumbers]" ) {
    int l1[] = {2, 4, 3},
        l2[] = {5, 6, 4},
        l3[] = {7, 0, 8};
    ListNode *a = create_list(l1),
             *b = create_list(l2),
             *c = create_list(l3);

    REQUIRE( is_equal(solve(a, b), c) );
}

TEST_CASE( "add two numbers [0]+[1,8]", "[addTwoNumbers]" ) {
    int l1[] = {0},
        l2[] = {1, 8},
        l3[] = {1, 8};
    ListNode *a = create_list(l1),
             *b = create_list(l2),
             *c = create_list(l3);

    REQUIRE( is_equal(solve(a, b), c) );
}

TEST_CASE( "add two numbers [9]+[1,9,9,9,9,9,9,9,9,9]", "[addTwoNumbers]" ) {
    int l1[] = {9},
        l2[] = {1, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        l3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    ListNode *a = create_list(l1),
             *b = create_list(l2),
             *c = create_list(l3);

    REQUIRE( is_equal(solve(a, b), c) );
}

TEST_CASE( "add two numbers [5]+[5]", "[addTwoNumbers]" ) {
    int l1[] = {5}, l2[] = {5}, l3[] = {0, 1};
    ListNode *a = create_list(l1),
             *b = create_list(l2),
             *c = create_list(l3);

    REQUIRE( is_equal(solve(a, b), c) );
}
