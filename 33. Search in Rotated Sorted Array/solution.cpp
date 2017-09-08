class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = static_cast<int>(nums.size()) - 1;
        while (begin < end) {
            int mid = (begin + end) >> 1;
            if (nums[mid] > nums[end])
                begin = mid + 1;
            else
                end = mid;
        }
        int mid = begin;
        begin = 0;
        end = static_cast<int>(nums.size()) - 1;
        while (begin <= end) {
            int middle = (begin + end) >> 1;
            int realMid = (middle + mid) % nums.size();
            if (nums[realMid] == target)
                return realMid;
            else if (nums[realMid] < target)
                begin = middle + 1;
            else
                end = middle - 1;
        }
        return -1;
    }
};