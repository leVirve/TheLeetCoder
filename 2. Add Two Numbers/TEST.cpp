#include "../framework/header.hpp"
#include "../framework/utils/list.hpp"

#ifdef C_SOLUTION
#include "solution.h"
#define SOLVE(...) addTwoNumbers(__VA_ARGS__)
#else
#include "solution.hpp"
Solution s;
#define SOLVE(...) s.addTwoNumbers(__VA_ARGS__)
#endif

TEST_CASE( "add two numbers [243]+[564]", "[addTwoNumbers]" ) {
    int l1[] = {2, 4, 3},
        l2[] = {5, 6, 4},
        l3[] = {7, 0, 8};
    ListNode *a = create_list(l1),
             *b = create_list(l2),
             *c = create_list(l3);

    REQUIRE( is_equal(SOLVE(a, b), c) );
}

TEST_CASE( "add two numbers [0]+[1,8]", "[addTwoNumbers]" ) {
    int l1[] = {0},
        l2[] = {1, 8},
        l3[] = {1, 8};
    ListNode *a = create_list(l1),
             *b = create_list(l2),
             *c = create_list(l3);

    REQUIRE( is_equal(SOLVE(a, b), c) );
}

TEST_CASE( "add two numbers [9]+[1,9,9,9,9,9,9,9,9,9]", "[addTwoNumbers]" ) {
    int l1[] = {9},
        l2[] = {1, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        l3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    ListNode *a = create_list(l1),
             *b = create_list(l2),
             *c = create_list(l3);

    REQUIRE( is_equal(SOLVE(a, b), c) );
}

TEST_CASE( "add two numbers [5]+[5]", "[addTwoNumbers]" ) {
    int l1[] = {5}, l2[] = {5}, l3[] = {0, 1};
    ListNode *a = create_list(l1),
             *b = create_list(l2),
             *c = create_list(l3);

    REQUIRE( is_equal(SOLVE(a, b), c) );
}
