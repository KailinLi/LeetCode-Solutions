class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        else if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 1; i < nums.size() - 1; ++i) {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        int res = dp[nums.size() - 1];
        fill(dp.begin(), dp.end(), 0);
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return max(res, dp[nums.size() - 1]);
    }
};