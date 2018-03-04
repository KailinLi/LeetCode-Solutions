class Solution {
public:
    bool match(string &s, string &p) {
        int i = 0, j = 0;
        int cnt = 0;
        while (i < s.size() && j < p.size()) {
            if (s[i] == p[j]) {
                ++i;
                ++j;
                ++cnt;
            }
            else {
                ++i;
            }
        }
        return cnt == p.size();
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int> success;
        vector<int> fail;
        int cnt = 0;
        for (int i = 0; i < words.size(); ++i) {
            bool flag = false;
            for (auto t : success) {
                if (match(words[t], words[i])) {
                    ++cnt;
                    flag = true;
                    break;
                }
            }
            for (auto t : fail) {
                if (match(words[t], words[i])) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                if (match(S, words[i])) {
                    success.push_back(i);
                    ++cnt;
                }
                else {
                    fail.push_back(i);
                }
            }
        }
        return cnt;
    }
};