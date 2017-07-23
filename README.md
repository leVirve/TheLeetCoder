# LeetCoder Framework

:sweat_drops:　Write your code and test them happily with full unit test features!　:sweat_drops:

## How to use

- Use [`Catch`](https://github.com/philsquared/Catch) as unit-test framework

    ```bash
    $ ./run.py test $id --catch
    ```

- If need quick and simple unit-test (only one testcase)


    ```bash
    $ ./run.py test $id
    ```

    *Use it carefully* :joy: , and read the [soure](/framework/header.hpp#L12).
    It's composed of simple marcos and has less functions than `Catch`, use this for quick compilation and tuning.


## Usage

- Generate template for question with command:


    ```bash
    $ ./run.py gen "231. Power of Two/solution"
    ```

    - The name of questionmust contain question id. And the structure looks like:

    ```
    $id. $question_title
    ├──  solution.hpp    # My LeetCode solution
    └──  TEST.cpp        # Testcases
    ```

- Now. Write Your Code !

    :thumbsup: which may looks like,
    ```c++
    /** 231. Power of Two/solution.hpp **/
    class Solution {
    public:
        bool isPowerOfTwo(int n) {
            return n > 0 && !(n & (n - 1));
        }
    };
    ```
    ```c++
    /** 231. Power of Two/TEST.cpp **/
    #include "solution.hpp"
    #include "../framework/header.hpp"

    TEST_CASE( "Power Of Two are tested", "[isPowerOfTwo]" ) {
        Solution s;
        REQUIRE( s.isPowerOfTwo(0) == false );
        REQUIRE( s.isPowerOfTwo(1) == true );
        REQUIRE( s.isPowerOfTwo(2) == true );
        REQUIRE( s.isPowerOfTwo(3) == false );
        REQUIRE( s.isPowerOfTwo(10) == false );
    }

    ```

- Test it with one-line !

    ```bash
    $ ./run.py test 231 --catch

    ==> Testing on #231
    ==> Compiling ...
    ==> Running ...
    ===============================================================================
    All tests passed (5 assertions in 1 test case)
    ```
