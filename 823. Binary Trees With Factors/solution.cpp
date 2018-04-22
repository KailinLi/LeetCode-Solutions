class Solution {
public:
    vector<pair<int, int>> findP(vector<int> &A, int k) {
        vector<pair<int, int>> res;
        for (int i = 0; i < k; ++i) {
            if (!(A[k] % A[i])) {
                auto f = lower_bound(A.begin() + i, A.begin() + k, A[k] / A[i]);
                if (f != A.begin() + k && *f == A[k] / A[i]) {
                    res.push_back(make_pair(i, distance(A.begin(), f)));
                }
            }
        }
        return res;
    }
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        vector<long long> dp(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            vector<pair<int, int>> && getF = findP(A, i);
            dp[i] = 1;
            for (auto p : getF) {
                cout << i << " " << p.first << "  " << p.second << endl;
                if (p.first != p.second)
                    dp[i] += ((dp[p.first] * dp[p.second]) << 1) % (1000000000 + 7);
                else
                    dp[i] += ((dp[p.first] * dp[p.second])) % (1000000000 + 7);
            }
        }
        long long sum = 0;
        for (auto f : dp) {
            sum = (sum + f) % (1000000000 + 7);
        }
        return (int)sum;
    }
};