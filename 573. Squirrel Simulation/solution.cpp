class Solution {
public:
    int step(vector<int>& s, vector<int>& t) {
        return abs(s[0] - t[0]) + abs(s[1] - t[1]);
    }
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        vector<int>distance;
        int res = INT_MAX;
        int sum = 0;
        for (auto nut : nuts) {
            int oneStep = step(nut, tree);
            sum += 2 * oneStep;
            distance.push_back(2 * oneStep);
        }
        for (int index = 0; index < nuts.size(); index++) {
            int tmp = sum;
            tmp -= distance[index];
            tmp += step(squirrel, nuts[index]) + step(nuts[index], tree);
            if (tmp < res) res = tmp;
        }
        return res;
    }
};