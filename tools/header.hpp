#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

#ifdef CATCH_TEST
# define CATCH_CONFIG_MAIN
# include "../Catch/single_include/catch.hpp"
#else
# define REQUIRE(x) assert(x)
# define TEST_CASE(doc, case) int main()
#endif
