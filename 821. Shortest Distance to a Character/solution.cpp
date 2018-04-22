class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res(S.length(), 0x3f3f3f3f);
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == C) {
                for (int m = i; m >= 0; --m) {
                    res[m] = min(res[m], i - m);
                }
                for (int m = i + 1; m < S.length(); ++m) {
                    res[m] = min(res[m], m - i);
                }
            }
        }
        return res;
    }
};