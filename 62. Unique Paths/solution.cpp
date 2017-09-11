class Solution {
    int **dp;
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        dp = new int*[m];
        for (int i = 0; i < m; ++i) {
            dp[i] = new int[n];
            dp[i][0] = 1;
            for (int j = 1; j < n; ++j) {
                dp[i][j] = -1;
            }
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (dp[i][j] != -1) continue;
                int res = 0;
                for (int k = 0; k <= i; ++k) {
                    res += dp[k][j - 1];
                }
                dp[i][j] = res;
                if (j < m && i < n)
                    dp[j][i] = res;
            }
        }
        return dp[m - 1][n - 1];
    }
};