class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        long long res = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += (nums[i] - nums[i - k]);
            res = max(res, sum);
        }
        return res / static_cast<double>(k);
    }
};