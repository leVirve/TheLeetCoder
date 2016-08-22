#include "solution.hpp"
#include "../tools/header.hpp"

TEST_CASE( "Power Of Two are tested", "[isPowerOfTwo]" ) {
    Solution s;

    REQUIRE( s.isPowerOfTwo(0) == false );
    REQUIRE( s.isPowerOfTwo(1) == true );
    REQUIRE( s.isPowerOfTwo(2) == true );
    REQUIRE( s.isPowerOfTwo(3) == false );
    REQUIRE( s.isPowerOfTwo(10) == false );
}
