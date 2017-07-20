class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int begin = -1, end = 0;
        int res = INT32_MAX;
        int sum = 0;
        while (end < nums.size()) {
            sum += nums[end];
            while (sum >= s) {
                res = min(res, end - begin);
                sum -= nums[++begin];
            }
            ++end;
        }
        return begin == -1 ? 0 : res;
    }
};