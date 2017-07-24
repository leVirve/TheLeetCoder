#include "../framework/header.hpp"
#include "../framework/utils/list.hpp"

#ifdef C_SOLUTION
#include "solution.h"
#define SOLVE(...) rotateRight(__VA_ARGS__)
#else
#include "solution.hpp"
Solution s;
#define SOLVE(...) s.rotateRight(__VA_ARGS__)
#endif

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

    REQUIRE( is_equal(SOLVE(in = create_list(l1), 2), ans1) );
    REQUIRE( is_equal(SOLVE(in = create_list(l1), 4), ans2) );
    REQUIRE( is_equal(SOLVE(in = create_list(l1), 5), ans3) );
    REQUIRE( is_equal(SOLVE(in = create_list(l1), 6), ans4) );
}


TEST_CASE( "rotate numbers []", "[rotateRight]" ) {
    ListNode *in = NULL,
             *ans1 = NULL;

    REQUIRE( is_equal(SOLVE(in, 0), ans1) );
}
