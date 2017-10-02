class Solution {
    int length = 1;
    int begin = 0;
    void testPalindrome(string& s, int begin, int end) {
        while (begin >= 0 && end < s.size() && s[begin] == s[end]) {
            --begin;
            ++end;
        }
        if (end - begin - 1 > length) {
            length = end - begin - 1;
            this->begin = begin + 1;
        }
    }
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        for (int i = 0; i < s.size(); ++i) {
            testPalindrome(s, i, i);
            testPalindrome(s, i, i + 1);
        }
        return s.substr(begin, length);
    }
};