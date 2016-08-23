#include "../framework/header.hpp"
#include "solution.hpp"


TEST_CASE( "Testcase doc string", "[case name]" ) {
    Solution s;

    REQUIRE( s.function_name(input) == output );
}
