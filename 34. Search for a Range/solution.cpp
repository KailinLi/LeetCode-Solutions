class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res{-1, -1};
        if (nums.empty()) return res;
        res[0] = findBegin(nums, target);
        res[1] = findEnd(nums, target);
        return res;
    }
    int findBegin(vector<int>& nums, int target) {
        int begin = 0;
        int end = static_cast<int>(nums.size());
        int middle = (begin + end) >> 1;
        while (middle != begin && middle != end) {
            if (nums[middle] >= target) end = middle;
            else begin = middle;
            middle = (begin + end) >> 1;
        }
        if (nums[middle] != target) ++middle;
        if (middle < 0 || middle >= nums.size()) return -1;
        return nums[middle] == target ? middle : -1;
    }
    int findEnd(vector<int>& nums, int target) {
        int begin = 0;
        int end = static_cast<int>(nums.size());
        int middle = (begin + end) >> 1;
        while (middle != begin && middle != end) {
            if (nums[middle] <= target) begin = middle;
            else end = middle;
            middle = (begin + end) >> 1;
        }
        if (nums[middle] != target) --middle;
        if (middle < 0 || middle >= nums.size()) return -1;
        return nums[middle] == target ? middle : -1;
    }
};