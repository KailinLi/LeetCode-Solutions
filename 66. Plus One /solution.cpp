class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (auto n = digits.rbegin(); n != digits.rend(); n++) {
            if (carry) {
                (*n)++;
                if (*n > 9) {
                    carry = true;
                    *n = 0;
                }
                else carry = false;
            }
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};