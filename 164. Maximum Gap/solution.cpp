struct Range {
    int count = 0;
    int max = INT_MIN;
    int min = INT_MAX;
};
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        auto size = nums.size();
        if (size == 0 || size == 1) {
            return 0;
        }
        int max = INT_MIN, min = INT_MAX;
        for (auto item : nums) {
            if (item > max) {
                max = item;
            }
            if (item < min) {
                min = item;
            }
        }
        int content = (max - min)/(size - 1);
        content = content == 0 ? 1 : content;
        int number = (max - min)/content + 1;
        vector<Range> bucket(number);
        for (auto item : nums) {
            int index = (item - min)/content;
            bucket[index].count++;
            bucket[index].max = bucket[index].max > item ? bucket[index].max : item;
            bucket[index].min = bucket[index].min < item ? bucket[index].min : item;
        }
        int tmp = min;
        int gap = 0;
        for (auto item : bucket) {
            if (item.count == 0) {
                continue;
            }
            gap = gap > (item.min - tmp) ? gap : (item.min - tmp);
            tmp = item.max;
        }
        return gap;
    }
};