class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> num(nums.size(), -1);
        stack<int>index;
        for (int i = 0; i < nums.size() * 2; i ++) {
            while (!index.empty() && nums[index.top()] < nums[i % nums.size()]) {
                num[index.top()] = nums[i % nums.size()];
                index.pop();
            }
            if (i < nums.size()) {
                index.push(i);
            }
        }
        return num;
    }
};