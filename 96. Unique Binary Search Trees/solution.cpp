class Solution {
public:
    int numTrees(int n) {
        vector<int>v(n + 1);
        v[0] = 1;
        v[1] = 1;
        v[2] = 2;
        int i = 3;
        while (i <= n) {
            int j = 0;
            while (j < i/2) {
                v[i] += 2 * v[j] * v[i - j - 1];
                j++;
            }
            if (i % 2) v[i] += v[j] * v[j];
            i++;
        }
        return v[n];
    }
};