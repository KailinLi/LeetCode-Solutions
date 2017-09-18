class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        auto begin = nums.begin();
        auto end = nums.end();
        auto current = begin;
        while (++begin != end) {
            if (*current != *begin && ++current != begin)
                *current = std::move(*begin);
        }
        return current - nums.begin() + 1;
    }
};