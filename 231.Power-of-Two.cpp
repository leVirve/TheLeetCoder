class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        char x = 0;
        while (n > 0) {
            char tmp = n & 0x1;
            if (tmp == 1) x += 1;
            if (x > 1) return false;
            n >>= 1;
        }
        return true;
    }
};