#include "../framework/header.hpp"

#ifdef C_SOLUTION
#include "solution.h"
#else
#include "solution.hpp"
#endif

return_type solve(input_type input) {
#ifdef C_SOLUTION
    return function_name(input);
#else
    Solution s;
    return s.function_name(input);
#endif
}


TEST_CASE( "Testcase doc string", "[case name]" ) {
    REQUIRE( solve(input) == output );
}
