class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>number;
        for (auto get : tokens) {
            if (get == "+") {
                int first = number.top();
                number.pop();
                int second = number.top();
                number.pop();
                number.push(second + first);
            }
            else if (get == "-") {
                int first = number.top();
                number.pop();
                int second = number.top();
                number.pop();
                number.push(second - first);
            }
            else if (get == "*") {
                int first = number.top();
                number.pop();
                int second = number.top();
                number.pop();
                number.push(second * first);
            }
            else if (get == "/") {
                int first = number.top();
                number.pop();
                int second = number.top();
                number.pop();
                number.push(second / first);
            }
            else {
                number.push(stoi(get));
            }
        }
        return number.top();
    }
};