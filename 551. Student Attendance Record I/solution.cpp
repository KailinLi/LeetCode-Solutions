class Solution {
public:
    bool checkRecord(string s) {
        int l = 0;
        int a = 0;
        for (auto c : s) {
            if (c == 'L') l++;
            else if (c == 'A') {
                a++;
                if (l < 3) l = 0;
            }
            else {
                if (l < 3) l = 0;
            }
        }
        if (l > 2 || a > 1) return false;
        return true;
    }
};