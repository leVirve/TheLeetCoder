class Solution {
    public:
        string reverseString(string s) {
            int len = s.length() - 1;
            for (int i = 0; i <= len / 2; ++i) swap(s[i], s[len - i]);
            return s;
        }
};
