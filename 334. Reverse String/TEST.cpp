#include "../tools/header.hpp"
#include "solution.hpp"

TEST_CASE( "Solution tested", "[reverseString]" ) {
    Solution s;

    REQUIRE( s.reverseString("ABCD") == "DCBA" );
}
