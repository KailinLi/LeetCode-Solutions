class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k == 0) return;
        vector<int> copy(nums.end() - k % nums.size(), nums.end());
        nums.erase(nums.end() - k % nums.size(), nums.end());
        nums.insert(nums.begin(), copy.begin(), copy.end());
    }
};