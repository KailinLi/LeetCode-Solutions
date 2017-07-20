class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto res = equal_range(nums.begin(), nums.end(), target);
        if (res.first == res.second) return {-1, -1};
        return {static_cast<int>(distance(nums.begin(), res.first)), static_cast<int>(distance(nums.begin(), res.second)) - 1};
    }
};