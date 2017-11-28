class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>>opt(A.size() + 1, vector<int>(B.size() + 1, 0));
		int res = 0;
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < B.size(); ++j) {
				if (A[i] == B[j]) {
					opt[i + 1][j + 1] = 1 + opt[i][j];
					res = std::max(res, opt[i + 1][j + 1]);
				}
			}
		}
		return res;
    }
};