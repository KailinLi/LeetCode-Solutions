class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> opt(triangle.size());
        opt[0].push_back(triangle[0][0]);
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0)
                    opt[i].push_back(opt[i - 1][0] + triangle[i][0]);
                else if (j == i)
                    opt[i].push_back(opt[i - 1][j - 1] + triangle[i][j]);
                else
                    opt[i].push_back(min(opt[i - 1][j - 1], opt[i - 1][j]) + triangle[i][j]);
            }
        }
        return *min_element(opt[triangle.size() - 1].begin(), opt[triangle.size() - 1].end());
    }
};