#include "../framework/header.hpp"
#include "../framework/utils/list.hpp"

#ifdef C_SOLUTION
#include "solution.h"
#define SOLVE(...) deleteNode(__VA_ARGS__)
#else
#include "solution.hpp"
Solution s;
#define SOLVE(...) s.deleteNode(__VA_ARGS__)
#endif


TEST_CASE( "Testcase doc string", "[case name]" ) {
    int l1[] = {1, 2, 3, 4},
        l2[] = {2, 3, 4};
    ListNode *in = create_list(l1),
             *ans = create_list(l2);

    SOLVE(in);
    REQUIRE( is_equal(in, ans) );
}
