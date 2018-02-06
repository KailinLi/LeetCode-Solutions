class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> opt(nums.size());
        opt[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            opt[i] = max(nums[i] + opt[i - 1], nums[i]);
        }
        return *max_element(opt.begin(), opt.end());
    }
};