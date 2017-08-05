class Solution {
public:
    vector<int> constructRectangle(int area) {
        if (!area) return vector<int>();
        int l = sqrt(area);
        while (area % l) --l;
        return vector<int>{area / l, l};
    }
};