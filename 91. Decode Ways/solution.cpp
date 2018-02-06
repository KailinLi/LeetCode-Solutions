class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return (s[0] - '1') < 0 ? 0 : 1;
        vector<int> opt(s.size());
        opt[0] = (s[0] - '1') < 0 ? 0 : 1;
        opt[1] = ((s[1] - '1') < 0 ? 0 : opt[0]) + (((s[0] - '1') >= 0 && stoi(s.substr(0, 2)) < 27) ? 1 : 0);
        for (int i = 2; i < s.size(); ++i) {
            opt[i] = ((s[i] - '1') < 0 ? 0 : opt[i - 1]) + (((s[i - 1] - '1') >= 0 && stoi(s.substr(i - 1, 2)) < 27) ? opt[i - 2] : 0);
        }
        return opt[s.size() - 1];
    }
};