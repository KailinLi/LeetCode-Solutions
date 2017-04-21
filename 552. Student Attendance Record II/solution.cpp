class Solution {
public:
    int checkRecord(int n) {
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 3;
        }
        long M = 1000000007;
        vector<long>dp{1, 1, 2};
        for (int i = 2; i < n; i++) {
            dp.push_back((dp[i - 2] + dp[i - 1] + dp[i]) % M);
        }
        long answer = (dp[n - 2] + dp[n - 1] + dp[n]) % M;
        for (int i = 0; i < n; i++) {
            answer += (dp[i + 1] * dp[n - i]) % M;
            answer %= M;
        }
        return (int)answer;
    }
};