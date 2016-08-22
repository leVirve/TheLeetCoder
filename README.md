#Leet

Here are my leet code solutions with unittests.

## Description

- Each question is strtucured in folders:

```
$id. $question_title
 ├──  solution.hpp    # My LeetCode solution
 └──  TEST.cpp        # Testcases
```

which may looks like
```c++
/** 231. Power of Two/solution.hpp **/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};


/** 231. Power of Two/TEST.cpp **/
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

```

## Test

- Take quick unit-test

```bash
$ ./run.py $id
```

- Use `Cactch` as unit-test framework

```bash
$ ./run.py $id catch
```

## Example
```bash
$  ./run.py 221 catch     

==============================================      
All tests passed (5 assertions in 1 test case)  
```
