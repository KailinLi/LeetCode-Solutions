class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>stack;
        for (auto c : num) {
            while (!stack.empty() && stack.back() > c && k > 0) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        while (k != 0) {
            stack.pop_back();
            k--;
        }
        string answer;
        for (auto c : stack) {
            if (answer.empty() && c == '0') {
                continue;
            }
            answer.push_back(c);
        }
        return answer.empty() ? "0" : answer;
    }
};