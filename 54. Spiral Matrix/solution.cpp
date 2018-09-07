class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int x, y, cur;
        res.push_back(matrix[x = 0][y = 0]);
        vis[x][y] = cur = 1;
        while (cur < row * col) {
            while (y + 1 < col && !vis[x][y + 1]) {
                res.push_back(matrix[x][y + 1]);
                vis[x][++y] = ++cur;
            }
            while (x + 1 < row && !vis[x + 1][y]) {
                res.push_back(matrix[x + 1][y]);
                vis[++x][y] = ++cur;
            }
            while (y - 1 >= 0 && !vis[x][y - 1]) {
                res.push_back(matrix[x][y - 1]);
                vis[x][--y] = ++cur;
            }
            while (x - 1 >= 0 && !vis[x - 1][y]) {
                res.push_back(matrix[x - 1][y]);
                vis[--x][y] = ++cur;
            }
        }
        return res;
    }
};