class Solution {
public:
    vector<int> cnt;
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        cnt.push_back(0);
        for (int i = 0; i <= A.size(); ++i) {
            cnt.push_back(cnt[i] + i + 1);
        }
        int res = 0;
        int tmpCnt = 0;
        int i = 0;
        while (i < A.size()) {
            if (A[i] > R) {
                res += cnt[tmpCnt];
                tmpCnt = 0;
            }
            else
                ++tmpCnt;
            ++i;
        }
        res += cnt[tmpCnt];
        tmpCnt = 0;
        i = 0;
        while (i < A.size()) {
            if (A[i] >= L) {
                res -= cnt[tmpCnt];
                tmpCnt = 0;
            }
            else
                ++tmpCnt;
            ++i;
        }
        res -= cnt[tmpCnt];
        return res;
    }
};