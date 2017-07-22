class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>pair;
        int res = 0;
        bool hasOdd = false;
        for (auto item : s) {
            auto obj = pair.find(item);
            if (obj != pair.end()) ++(obj->second);
            else pair.insert(make_pair(item, 1));
        }
        for (auto begin = pair.begin(); begin != pair.end(); ++begin) {
            res += (begin->second >> 1) << 1;
            if (!hasOdd && begin->second % 2) hasOdd = true;
        }
        return res + (hasOdd ? 1 : 0);
    }
};