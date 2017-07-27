class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min_st = INT32_MAX, min_nd = INT32_MAX;
        int max_st = INT32_MIN, max_nd = INT32_MIN, max_rd = INT32_MIN;
        for (auto item : nums) {
            if (min_st > item) {
                min_nd = min_st;
                min_st = item;
            }
            else if (min_nd > item) {
                min_nd = item;
            }
            if (max_st < item) {
                max_rd = max_nd;
                max_nd = max_st;
                max_st = item;
            }
            else if (max_nd < item) {
                max_rd = max_nd;
                max_nd = item;
            }
            else if (max_rd < item) {
                max_rd = item;
            }
        }
        return max(min_st * min_nd * max_st, max_st * max_nd * max_rd);
    }
};