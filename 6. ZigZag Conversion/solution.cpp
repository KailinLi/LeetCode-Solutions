class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows == 0) return s;
        vector<vector<char>> matrix(numRows);
        for (int i = 0; i < s.size(); ++i) {
            int row = i % (2 * numRows - 2);
            if (row < numRows) {
                matrix[row].push_back(s[i]);
            }
            else {
                matrix[2 * numRows - 2 - row].push_back(s[i]);
            }
        }
        string res;
        for_each(matrix.begin(), matrix.end(), [&res](vector<char> v) {
            for_each(v.begin(), v.end(), [&res](char c) {res += c;});
        });
        return res;
    }
};