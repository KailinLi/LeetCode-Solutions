class Solution {
private:
    vector<string>number;
    stack<char>option;
    string element;
    stack<int>answer;
public:
    int calculate(string s) {
        for (auto c : s) {
            switch (c) {
                case ' ':
                    continue;
                case '+':case '-':
                    if (!element.empty()) {
                        number.push_back(element);
                        element.clear();
                    }
                    while (!option.empty() && option.top() != '(') {
                        string get(1, option.top());
                        number.push_back(get);
                        option.pop();
                    }
                    option.push(c);
                    break;
                case '(':
                    if (!element.empty()) {
                        number.push_back(element);
                        element.clear();
                    }
                    option.push(c);
                    break;
                case ')':
                    if (!element.empty()) {
                        number.push_back(element);
                        element.clear();
                    }
                    while (option.top() != '(') {
                        string get(1, option.top());
                        number.push_back(get);
                        option.pop();
                    }
                    option.pop();
                    break;
                default:
                    element.push_back(c);
                    break;
            }
        }
        if (!element.empty()) {
            number.push_back(element);
        }
        while (!option.empty()) {
            string get(1, option.top());
            number.push_back(get);
            option.pop();
        }
        for (auto i : number) {
            if (i == "+") {
                int first = answer.top();
                answer.pop();
                int second = answer.top();
                answer.pop();
                answer.push(second + first);
            }
            else if (i == "-") {
                int first = answer.top();
                answer.pop();
                int second = answer.top();
                answer.pop();
                answer.push(second - first);
            }
            else {
                answer.push(stoi(i));
            }
        }
        return answer.top();
    }
};