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

bool solve(ListNode* a) {
#ifdef C_SOLUTION
    return hasCycle(a);
#else
    Solution s;
    return s.hasCycle(a);
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


TEST_CASE( "has cycle [1, 2, 3, 4, 5, 6, 7, 8, 9]", "[hasCycle]" ) {
    int l1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *in1 = create_list(l1),
             *in2 = create_list(l1);

    ListNode* p = in2;
    while (p->next) p = p->next;
    p->next = in2;

    REQUIRE( solve(in1) == false );
    REQUIRE( solve(in2) == true );
}


TEST_CASE( "has cycle [1, 2, 3, 4]", "[hasCycle]" ) {
    int l1[] = {1, 2, 3, 4};
    ListNode *in1 = create_list(l1),
             *in2 = create_list(l1);

    ListNode* p = in2;
    while (p->next) p = p->next;
    p->next = in2;

    REQUIRE( solve(in1) == false );
    REQUIRE( solve(in2) == true );
}
