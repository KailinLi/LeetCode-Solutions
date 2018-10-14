class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'I') {
                if (i < s.size() - 1 && s[i + 1] == 'V') {
                    sum += 4;
                    ++i;
                }
                else if (i < s.size() - 1 && s[i + 1] == 'X') {
                    sum += 9;
                    ++i;
                }
                else ++sum;
            }
            else if (s[i] == 'X') {
                if (i < s.size() - 1 && s[i + 1] == 'L') {
                    sum += 40;
                    ++i;
                }
                else if (i < s.size() - 1 && s[i + 1] == 'C') {
                    sum += 90;
                    ++i;
                }
                else sum += 10;
            }
            else if (s[i] == 'C') {
                if (i < s.size() - 1 && s[i + 1] == 'D') {
                    sum += 400;
                    ++i;
                }
                else if (i < s.size() - 1 && s[i + 1] == 'M') {
                    sum += 900;
                    ++i;
                }
                else sum += 100;
            }
            else if (s[i] == 'V') sum += 5;
            else if (s[i] == 'L') sum += 50;
            else if (s[i] == 'D') sum += 500;
            else sum += 1000;
        }
        return sum;
    }
};