#include "../framework/header.hpp"
#include "../framework/utils/list.hpp"

#ifdef C_SOLUTION
#include "solution.h"
#define SOLVE(...) hasCycle(__VA_ARGS__)
#else
#include "solution.hpp"
Solution s;
#define SOLVE(...) s.hasCycle(__VA_ARGS__)
#endif

TEST_CASE( "has cycle [1, 2, 3, 4, 5, 6, 7, 8, 9]", "[hasCycle]" ) {
    int l1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *in1 = create_list(l1),
             *in2 = create_list(l1);

    ListNode* p = in2;
    while (p->next) p = p->next;
    p->next = in2;

    REQUIRE( SOLVE(in1) == false );
    REQUIRE( SOLVE(in2) == true );
}


TEST_CASE( "has cycle [1, 2, 3, 4]", "[hasCycle]" ) {
    int l1[] = {1, 2, 3, 4};
    ListNode *in1 = create_list(l1),
             *in2 = create_list(l1);

    ListNode* p = in2;
    while (p->next) p = p->next;
    p->next = in2;

    REQUIRE( SOLVE(in1) == false );
    REQUIRE( SOLVE(in2) == true );
}
