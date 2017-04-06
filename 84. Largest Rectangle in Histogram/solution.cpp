class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int max = 0;
        stack<int> indexStack;
        for (int index = 0; index < heights.size(); index++) {
            while (!indexStack.empty() && heights[indexStack.top()] >= heights[index]) {
                int high = heights[indexStack.top()];
                indexStack.pop();
                int res = indexStack.empty() ? -1 : indexStack.top();
                max = max > high * (index - res - 1) ? max : high * (index - res - 1);
            }
            indexStack.push(index);
        }
        return max;
    }
};