class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s = INT_MIN;
        stack<int>number;
        for (auto it = nums.rbegin(); it != nums.rend(); it++) {
            if (*it < s) {
                return true;
            }
            while (!number.empty() && *it > number.top()) {
                s = number.top();
                number.pop();
            }
            number.push(*it);
        }
        return false;
    }
};