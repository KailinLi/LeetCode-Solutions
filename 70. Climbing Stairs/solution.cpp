class Solution {
public:
    int climbStairs(int n) {
        vector<int> opt(n);
        opt[0] = 1;
        opt[1] = 2;
        for (int i = 2; i < n; ++i) {
            opt[i] = opt[i - 1] + opt[i - 2];
        }
        return opt[n - 1];
    }
};