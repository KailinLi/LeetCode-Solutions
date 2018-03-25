class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> top;
        vector<int> left;
        int l = grid.size();
        int w = grid[0].size();
        for (int i = 0; i < l; ++i) {
            int tmp_max = -1;
            for (int j = 0; j < w; ++j) {
                tmp_max = max(tmp_max, grid[i][j]);
            }
            top.push_back(tmp_max);
        }
        for (int i = 0; i < w; ++i) {
            int tmp_max = -1;
            for (int j = 0; j < l; ++j) {
                tmp_max = max(tmp_max, grid[j][i]);
            }
            left.push_back(tmp_max);
        }
        int res = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < w; ++j) {
                int get_max = min(top[i], left[j]);
                res += get_max - grid[i][j];
            }
        }
        return res;
    }
};