class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int begin = 0;
        int end = static_cast<int>(numbers.size()) - 1;
        while (begin < end) {
            if (target == numbers[begin] + numbers[end]) {
                res.push_back(begin + 1);
                res.push_back(end + 1);
                break;
            }
            else if (numbers[begin] + numbers[end] < target) ++begin;
            else --end;
        }
        return res;
    }
};