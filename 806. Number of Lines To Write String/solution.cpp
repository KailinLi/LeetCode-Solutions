class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 1, tmp_sum = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (tmp_sum + widths[S[i] - 'a'] > 100) {
                ++line;
                tmp_sum = widths[S[i] - 'a'];
            }
            else {
                tmp_sum += widths[S[i] - 'a'];
            }
        }
        return vector<int>{line, tmp_sum};
    }
};