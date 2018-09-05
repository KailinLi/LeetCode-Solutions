class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int offset = nums.size() * 100;
        vector<vector<int>> dp(2, vector<int>(100 * nums.size() * 2));
        for (int i = -offset; i < offset; ++i) dp[0][i + offset] = false;
        dp[0][offset] = true;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = -offset; j < offset; ++j) {
                dp[(i + 1) % 2][j + offset] = false;
                if (j + nums[i] < offset && dp[i % 2][j + nums[i] + offset]) {
                    if (i + 1 == nums.size() && !j) return true;
                    dp[(i + 1) % 2][j + offset] = true;
                }
                if (j - nums[i] >= -offset && dp[i % 2][j - nums[i] + offset]) {
                    if (i + 1 == nums.size() && !j) return true;
                    dp[(i + 1) % 2][j + offset] = true;
                }
            }
        }
        return false;
    }
};