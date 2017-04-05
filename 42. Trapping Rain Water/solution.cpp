class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int answer = 0;
        int maxLeft = 0, maxRight = 0;
        auto left = height.begin(), right = --height.end();
        while (left < right) {
            if (*left < *right) {
                if (*left > maxLeft) {
                    maxLeft = *left;
                }
                else {
                    answer += maxLeft - *left;
                }
                left++;
            }
            else {
                if (*right > maxRight) {
                    maxRight = *right;
                }
                else {
                    answer += maxRight - *right;
                }
                right--;
            }
        }
        return answer;
    }
};