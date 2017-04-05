class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for (auto get : s) {
            switch (get) {
                case '(':case '{':case '[':
                    ss.push(get);
                    break;
                case ')':
                    if (ss.empty()) return false;
                    if (ss.top() == '(') ss.pop();
                    else return false;
                    break;
                case '}':
                    if (ss.empty()) return false;
                    if (ss.top() == '{') ss.pop();
                    else return false;
                    break;
                case ']':
                    if (ss.empty()) return false;
                    if (ss.top() == '[') ss.pop();
                    else return false;
                    break;
                default:
                    break;
            }
        }
        return ss.empty();
    }
};