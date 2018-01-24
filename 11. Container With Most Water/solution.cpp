class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = INT32_MIN;
        int h;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            h = min(height[i], height[j]);
            maxA = max(maxA, (j - i) * h);
            while (height[i] <= h && i < j)
                ++i;
            while (height[j] <= h && i < j)
                --j;
        }
        return maxA;
    }
};