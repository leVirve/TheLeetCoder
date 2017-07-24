#include "../framework/header.hpp"

#ifdef C_SOLUTION
#include "solution.h"
#define SOLVE(...) solver_name(__VA_ARGS__)
#else
#include "solution.hpp"
Solution s;
#define SOLVE(...) s.solver_name(__VA_ARGS__)
#endif


TEST_CASE( "Testcase_doc_string", "[solver_name]" ) {
    REQUIRE( SOLVE(input) == output );
}
