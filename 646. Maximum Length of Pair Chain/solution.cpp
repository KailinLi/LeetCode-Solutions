class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> dp(pairs.size(), 1);
        sort(pairs.begin(), pairs.end(), [](vector<int>& i, vector<int>& j){return i[0] < j[0];});
        for (size_t i = 1; i < pairs.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};