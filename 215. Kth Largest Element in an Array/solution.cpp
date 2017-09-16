class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty()) return -1;
        return quickSearch(nums, 0, nums.size() - 1, k - 1);
    }
    int quickSearch(vector<int>& nums, int begin, int end, int k) {
        int i = begin, j = end;
        int pivot = nums[j];
        while (i < j) {
            if (nums[i] > pivot) {
                swap(nums[i], nums[--j]);
            }
            else ++i;
        }
        swap(nums[i], nums[end]);
        if (end - i == k) return nums[i];
        else if (end - i < k) return quickSearch(nums, begin, i - 1, k - end + i - 1);
        else return quickSearch(nums, i + 1, end, k);
    }
};