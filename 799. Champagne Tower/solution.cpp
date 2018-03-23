class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double cup[101][101] = {0.0};
        cup[0][0] = poured;
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (cup[i][j] > 1) {
                    cup[i + 1][j] += (cup[i][j] - 1) / 2;
                    cup[i + 1][j + 1] += (cup[i][j] - 1) / 2;
                    cup[i][j] = 1;
                }
            }
        }
        return cup[query_row][query_glass];
    }
};