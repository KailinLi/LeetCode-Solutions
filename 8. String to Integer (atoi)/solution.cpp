class Solution {
public:
    int myAtoi(string str) {
        size_t i = 0;
        bool isNegative = false;
        while (isspace(str[i])) ++i;
        unsigned long res = 0;
        if (str[i] == '+') ++i;
        else if (str[i] == '-') {
            isNegative = true;
            ++i;
        }
        unsigned long size = static_cast<unsigned long>(INT32_MAX) + 1;
        for (; i < str.size(); ++i) {
            if (!isdigit(str[i])) {
                break;
            }
            res = res * 10 + (str[i] - '0');
            if (res >= size) break;
        }
        if (res >= size) {
            return (isNegative ? INT32_MIN : INT32_MAX);
        }
        return (isNegative ? -res : res);
    }
};