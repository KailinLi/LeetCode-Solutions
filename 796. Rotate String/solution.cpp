class Solution {
public:
    bool rotateString(string A, string B) {
        for (int i = 0; i < A.size(); ++i) {
            rotate(A.begin(), A.begin() + 1, A.end());
            if (A == B)
                return true;
        }
        return false;
    }
};